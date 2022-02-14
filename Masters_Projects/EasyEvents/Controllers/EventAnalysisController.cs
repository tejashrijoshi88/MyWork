/**** This controller contains the API end points to give data related to analysis of event    ****
 **** contains methods to get count of participants, count of attendees for given event -(GET) ****
 **** Author - Tejashri Joshi                                                                  ****
 **** Date   - 12/9/2020                                                                       ****/
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using EasyEvents.Data;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace EasyEvents.Controllers
{
    [Route("[controller]")]
    [ApiController]
    public class EventAnalysisController : ControllerBase
    {
        private readonly AppDbContext dbContext;

        public EventAnalysisController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }

        //get event analysis
        [HttpGet]
        [Route("getEventAnalysis/{eventName}")]
        public async Task<IActionResult> getEventAnalysis( string eventName)
        {
            // create an object for controllers
            var evObj = new EventController(dbContext);
            try
            {
                //get attendance and participant count
                var evDeatils = evObj.getEventByName(eventName);
                int registerUserCount = await dbContext.UserEvents.CountAsync(c => c.EventId == evDeatils.Result.EventId);
                int attendanceCount = await dbContext.UserEvents.Where(c => c.EventId == evDeatils.Result.EventId).Where(i => i.IsAttended == "Y").CountAsync();
                return Ok(new { registrationCount = registerUserCount, attendedCount = attendanceCount }) ;
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }
  


        //get event wise count
        [HttpGet]
        [Route("getRegistrationPerEvent")]
        public async Task<IActionResult> getCountPerEvent()
        {
            var Countdata = new ArrayList();
            var labels = new ArrayList();
            try
            {
                // fetch event with max participants
                var eve = dbContext.UserEvents.Include(e => e.Events).GroupBy(p => p.Events.EventName).Select(g => new { name = g.Key, count = g.Count() }).OrderByDescending(c=>c.count);
                foreach (var i in eve)
                {
                    labels.Add(i.name);
                    Countdata.Add(i.count);
                }
                return Ok(new { data= Countdata, label=labels});
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }



    }
}
