/**** This controller contains the API end points to event check in for user                ****
 **** user can do check in before 24 hrs of the event day                                   ****
 **** contains methods to fetch participant by RFID tag and mark checked in (GET,PUT)       ****
 **** response shared is in xml format for these end points                                 ****
 **** Author - Tejashri Joshi                                                               ****
 **** Date   - 12/9/2020                                                                    ****/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using EasyEvents.Data;
using EasyEvents.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace EasyEvents.Controllers
{
    [Route("[controller]")]
    [ApiController]
    public class EventCheckinController : ControllerBase
    {
        private readonly AppDbContext dbContext;

        public EventCheckinController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }
        // get participant using RFID with xml response
        [HttpGet]
        [Produces("application/xml")]
        [Route("searchParticipant/{RFID}")]
        public async Task<UserEvents> getParticipant(string RFID)
        {
                var user = await dbContext.UserEvents.FirstOrDefaultAsync(c => c.RFIDTagId == RFID);
                return user;
        }

        // Update userEvent table to update isAttended flag . the response will be in xml 
        
        [HttpPut]
        [Produces("application/xml")]
        [Route("updateUserEvent/{RFID}")]
        public async Task<IActionResult> checkIfUserAttended(string RFID)
        {
            try
            {

                // check if user has  signed up
                
                UserEvents eventExist = await getParticipant(RFID);
                
                //if user found update isAttended
                if (eventExist != null)
                {
                    // check if event date is past date or it is within 24 hrs from today
                    var eventDate = dbContext.Events.SingleOrDefault(a => a.EventId == eventExist.EventId).DateTime;
                    if ((eventDate - DateTime.Now).TotalDays < 2 && eventDate > DateTime.Today)
                    {
                        eventExist.IsAttended = "Y";
                        await dbContext.SaveChangesAsync();
                        return Ok("Registration Successful!!!");
                    }
                    return BadRequest("Event is either past event or you are checking up early..Check in start before 24 hrs of event day" );
                }
                // post userevent details to table and return RFIDTag
                return NotFound("You have not signed up for the event");
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }
    }
}
