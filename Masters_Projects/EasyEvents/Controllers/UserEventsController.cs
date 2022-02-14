/**** This controller contains the API end points to give data related to userEvents        ****
 **** contains methods to register event for user, cancle event for user, get user events   ****
 **** by id , name and all to get future events - (GET,POST,DELETE)                         ****
 **** Author - Tejashri Joshi                                                               ****
 **** Date   - 12/9/2020                                                                    ****/
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using EasyEvents.Data;
using EasyEvents.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Newtonsoft.Json.Linq;

namespace EasyEvents.Controllers
{
    [Route("[controller]")]
    [ApiController]
    public class UserEventsController : ControllerBase
    {
        private readonly AppDbContext dbContext;

        public UserEventsController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }
        
        // method to get all future events signed up by user
        // [EnableCors("AnotherPolicy")]
        [HttpGet]
        [Route("allEvents/future/{userId:int}")]
        public async Task<IActionResult> getFutureEventsByUser(int userId)
        {

            try
            {
                // fetch the future events signed up by user
                var futureEvent = await dbContext.UserEvents.Include(i => i.Events.Venue).
                                                            Where(u => u.GuestId == userId & u.Events.DateTime >= DateTime.Today).
                                                            Select(u => new
                                                            {
                                                                eventId= u.EventId,
                                                                eventName = u.Events.EventName
                                                                             ,
                                                                venue = u.Events.Venue.VenueName + " " + u.Events.Venue.Address + " " + u.Events.Venue.City + " " + u.Events.Venue.State + " " + u.Events.Venue.ZipCode
                                                                             ,
                                                                date = u.Events.DateTime
                                                                             ,
                                                                time = u.Events.Time,
                                                                RFID = u.RFIDTagId
                                                            }).ToListAsync();
                //if find some events send in response
                if (futureEvent.Count != 0)
                {
                    return Ok(futureEvent);
                }
                //send 404 not found error
                return NotFound("User has not signed up for any event");         
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }
        // method to get all future events signed up by user
        // [EnableCors("AnotherPolicy")]
        [HttpGet]
        [Route("allEvents/past/{userId:int}")]
        public async Task<IActionResult> getPastEventsByUser(int userId)
        {

            try
            {
                // fetch the future events signed up by user
                var futureEvent = await dbContext.UserEvents.Include(i => i.Events.Venue).
                                                            Where(u => u.GuestId == userId & u.Events.DateTime < DateTime.Today).
                                                            Select(u => new
                                                            {
                                                                eventId = u.EventId,
                                                                eventName = u.Events.EventName
                                                                             ,
                                                                venue = u.Events.Venue.VenueName + " " + u.Events.Venue.Address + " " + u.Events.Venue.City + " " + u.Events.Venue.State + " " + u.Events.Venue.ZipCode
                                                                             ,
                                                                date = u.Events.DateTime
                                                                             ,
                                                                time =u.Events.Time,
                                                                RFID = u.RFIDTagId
                                                            }).ToListAsync();
                //if find some events send in response
                if (futureEvent.Count != 0)
                {
                    return Ok(futureEvent);
                }
                //send 404 not found error
                return NotFound("User has not signed up for any event");
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }

        // local class to define the input variables for adding event
        public class addevent
        {
            public int EventId { get; set; }
            public int GuestId { get; set; }
            
        }
        // Add the user event
        //[EnableCors("AnotherPolicy")]
        [HttpPost]
        [Route("insertUserEvent")]
        public async Task<IActionResult> postEventsByUser([FromBody] addevent ue)
        {
            // create object for weatherForecast controller
            var weatherObj = new ExternalServicesController();

            
            try
            {
                // get event details by Id
                
                var ev= dbContext.Events.SingleOrDefault(a => a.EventId == ue.EventId);
                // get event date from event id
                DateTime evDate= ev.DateTime;
                
                // get details of user by id
                
                var usr = dbContext.Users.SingleOrDefault(a => a.UserId == ue.GuestId);
                //if event is having past date show error
                if (evDate <DateTime.Today)
                {
                    return BadRequest("Event is past and already done");
                }
                // check if user has already signed up
                var eventExist = await dbContext.UserEvents.SingleOrDefaultAsync(c => c.GuestId == ue.GuestId & c.EventId == ue.EventId);

                //if event is already signed up by user send error
                if (eventExist != null)
                {
                    return BadRequest("User has already signed up for the event");
                }

                Guid g = Guid.NewGuid();
                // post userevent details to table and return RFIDTag
                var userevent = new UserEvents
                {
                    GuestId = ue.GuestId,
                    EventId = ue.EventId,
                    RFIDTagId = g.ToString()
                };
                // save details to database
                dbContext.UserEvents.Add(userevent);
                await dbContext.SaveChangesAsync();
                // send email to user
                weatherObj.SendEmail(usr.EmailAddress,usr.FirstName,ev.EventName, "registered").Wait();
                // add custome header
                Response.Headers.Add("RFID", userevent.RFIDTagId);
                return Ok(new { RFID=userevent.RFIDTagId });              
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }


        // cancel the user event
        [HttpDelete]
        [Route("cancleEventSignUp/{userId:int}/{eventId:int}")]
        public async Task<IActionResult> cancleEventSignUp(int eventId, int userId)
        {
            // create object for weatherForecast controller
            var weatherObj = new ExternalServicesController();

            try
            {
                // get event details by Id
               
                var ev = dbContext.Events.SingleOrDefault(a => a.EventId == eventId);
                // get details of user by id
               
                var usr = dbContext.Users.SingleOrDefault(a => a.UserId == userId);
                // fetch the participant  for given event
                var userevent = await dbContext.UserEvents.FirstOrDefaultAsync(c => c.EventId == eventId & c.GuestId == userId);
                // send 404 if not found
                if (userevent == null)
                {
                    return NotFound("Event not Found");
                }
                //delete the userEvent
                dbContext.UserEvents.Remove(userevent);
                await dbContext.SaveChangesAsync();
                // send email to user
                weatherObj.SendEmail(usr.EmailAddress, usr.FirstName, ev.EventName,"unsubscribed").Wait();
                Response.Headers.Add("status", "event Cancelled Successfully");
                return Ok(new { message = "Event canceled successfully" });
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }

        }

    }
}
