/**** This controller contains the API end points to give data related to eventtype         ****
 **** contains methods for fetching all event types and by name  (GET)                      ****
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
    public class EventTypeController : ControllerBase
    {
        private readonly AppDbContext dbContext;

        public EventTypeController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }

        //GET All eventsTypes
        [HttpGet]
        [Route("getAllEventTypes")]
        public async Task<IActionResult> getAllEventTypes()
        {
            try
            {
                var allEventTypes = await dbContext.EventTypes.ToListAsync();
                Response.Headers.Add("EventTypeCount", allEventTypes.Count.ToString());
                return Ok(allEventTypes);
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }

        // Get eventType for a given name
        [HttpGet]
        [Route("getEventType/{eventTypeName}")]
        public async Task<EventType> getEventType(string eventTypeName)
        {
            // fetch event type details from database
           var eventtype =  await dbContext.EventTypes.SingleOrDefaultAsync(e => e.EventTypeName == eventTypeName);
            return eventtype;


        }
    }
}
