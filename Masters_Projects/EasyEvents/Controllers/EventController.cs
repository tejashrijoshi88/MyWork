/**** This controller contains the API end points to give data related to events            ****
 **** contains methods to create, delete, edit event. It also has methods to fetch events   ****
 **** by id , name and all to get future events - (GET,POST,PUT,DELETE)                     ****
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
    public class EventController : ControllerBase
    {
        private readonly AppDbContext dbContext;
 
        public EventController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }
        // Get event for a given event id
        [HttpGet]
        [Route("getEventById/{eventId}")]
        public async Task<Events> getEventById(int eventId)
        {
            // fetch data from database for event id
            var events = await dbContext.Events.SingleOrDefaultAsync(e => e.EventId == eventId);
            return events;
        }
        // Get event for a given event name
        [HttpGet]
        [Route("getEventByName/{eventName}")]
        public async Task<Events> getEventByName(string eventName)
        {
            // fetch data from database for event name
            var events = await dbContext.Events.SingleOrDefaultAsync(e => e.EventName == eventName);
            return events;
        }

        //GET All events
        [HttpGet]
        [Route("getAllEvents")]
        public async Task<IActionResult> getAllEvents()
        {
            try
            {
                // fetch event id, name, venue, date, time for all events 
                var allEvents = await dbContext.Events.Select(u => new
                { eventId = u.EventId,
                    eventName = u.EventName
                                                                             ,
                    venue = u.Venue.VenueName + " " + u.Venue.Address + " " + u.Venue.City + " " + u.Venue.State + " " + u.Venue.ZipCode
                                                                             ,
                    date = u.DateTime,
                    time = u.Time  }).ToListAsync();
                // set custom header
                Response.Headers.Add("EventCount", allEvents.Count.ToString());
                return Ok(allEvents);
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }

        // Get events for a given event type
        [HttpGet]
        [Route("getEvent/byType/{eventTypeName}")]
        public async Task<IActionResult> getEventByType(string eventTypeName)
        {
            try
            {
                // create an object for controllers
                var evType = new EventTypeController(dbContext);
                // get event type id from name
                var eve = evType.getEventType(eventTypeName);
                //int evTypeId = dbContext.EventTypes.SingleOrDefault(a => a.EventTypeName == eventTypeName).EventTypeId;
                var events = await dbContext.Events.Where(e => e.EventTypeId == eve.Result.EventTypeId)
                                                   .Select(u => new
                                                   {
                                                       eventId = u.EventId,
                                                       eventName = u.EventName,
                                                       venue = u.Venue.VenueName + " " + u.Venue.Address + " " + u.Venue.City + " " + u.Venue.State + " " + u.Venue.ZipCode,
                                                       date = u.DateTime,
                                                       time=u.Time
                                                   }).ToListAsync(); ;
                if (events.Count != 0)
                {
                    // set custom header and send responses
                    Response.Headers.Add("EventCountByName", events.Count.ToString());
                    return Ok(events);
                }
                return NotFound("Event not found");
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }
        //search events starting by given name string
        [HttpGet]
        [Route("getEvent/byName/{Eventname:minlength(1)}")]
        public async Task<IActionResult> searchEventByName(string Eventname)
        {
            try
            {
                // fetch events data from database for given string
                var events = await dbContext.Events.Where(c => c.EventName.StartsWith(Eventname))
                                       .Select(u => new
                                       {
                                           eventId = u.EventId,
                                           eventName = u.EventName,
                                           venue = u.Venue.VenueName + " " + u.Venue.Address + " " + u.Venue.City + " " + u.Venue.State + " " + u.Venue.ZipCode,
                                           date = u.DateTime,
                                           time=u.Time
                                       }).ToListAsync();
                if (events.Count != 0)
                {
                    // set custom header and send response
                    Response.Headers.Add("EventCount", events.Count.ToString());
                    return Ok(events);
                }
                return NotFound("Event not found");
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }

        // local class to define the input variables for adding event
        public class inputEvent 
        {
            public String EventName { get; set; }
            public DateTime DateTime { get; set; }
            public string Time { get; set; } 
            public String Description { get; set; }
            public String EventType { get; set; }
            public int HostId { get; set; }
            public string Venue { get; set; }
        }
        // Add new event for given details
        [HttpPost]
        [Route("addEvent")]
        public async Task<IActionResult> createEvent([FromBody] inputEvent events)
        {
 
            try
            {

                // checking event exists
                var eventExist = dbContext.Events.SingleOrDefault(a => a.EventName == events.EventName);
                
                
                if (eventExist !=null)
                {
                    return BadRequest("Event with same name already exists");
                }
                // create an object of events type
                var newEvent = new Events
                {
                    EventName = events.EventName,
                    DateTime = events.DateTime,
                    Time=      events.Time,
                    Description = events.Description,
                    EventTypeId = dbContext.EventTypes.SingleOrDefault(a => a.EventTypeName == events.EventType).EventTypeId,//get event by id 
                    HostId = events.HostId,
                    VenueId =  dbContext.Venues.SingleOrDefault(a => a.VenueName == events.Venue).VenueId //get venue by id
                };
                // insert into database
                dbContext.Events.Add(newEvent);
                await dbContext.SaveChangesAsync();
                return Ok(new { message = "Event created successfully" });
            }
            catch(Exception e)
            {
                return BadRequest(e.Message);
            }
        }

        //edit the event
        [HttpPut]
        [Route("editEvent")]
        public async Task<IActionResult> updateEvent([FromBody] Events eventToUpdate)
        {
            try
            {
                // fetch event from database
                var updateEvent = await dbContext.Events
                                  .SingleOrDefaultAsync
                                  (i => i.EventName == eventToUpdate.EventName);
                //send 404 if not found
                if (updateEvent == null)
                {
                    return NotFound(new { message = $"Event with id {eventToUpdate.EventId} not found." });
                }
                // update event with new details
                updateEvent = eventToUpdate;
                dbContext.Events.Update(updateEvent);
                await dbContext.SaveChangesAsync();
                return Ok(new { message = "Event updated successfully" });
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }
        // delete the event for given id
        [HttpDelete]
        [Route("cancleEvent/{eventId}")]
        public async Task<IActionResult> cancleEvent(int eventId)
        {
            try
            {
                // fetch the event count for given eventid
                //var eventtoDelete = getEventById(eventId);
                var eventtoDelete=await dbContext.Events.FirstOrDefaultAsync(e => e.EventId == eventId);
                // send 404 if not found
                if (eventtoDelete== null)
                {
                    return NotFound("Event not Found");
                }
                // send error if it is past event
                if (eventtoDelete.DateTime < DateTime.Today)
                {
                    return BadRequest("Event is past event");
                }
                // remove all entries for participant from userEvents table
                var userevent= dbContext.UserEvents.Where(ue => ue.EventId == eventtoDelete.EventId);
                foreach (var ue in userevent)
                {
                    dbContext.UserEvents.Remove(ue);
                }
                //delete the Event from events table
                dbContext.Events.Remove(eventtoDelete);
                await dbContext.SaveChangesAsync();
                return Ok(new { message = "Event canceled successfully" });
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }

        }

        // get weather for event day
        [HttpGet]
        [Route("getWeather/{eventId:int}")]
        public async Task<IActionResult> getWeatherOnEventDay(int eventId)
        {
            try
            {
                // create object for weatherForecast controller
                var weatherObj = new ExternalServicesController(); 
                // fetch the event  for given eventid
                var eventDetails = await dbContext.Events.Include(v=>v.Venue).FirstOrDefaultAsync(e => e.EventId == eventId);
                // if event day date is greater then 10 days from today or if it is past date show error
                if ((eventDetails.DateTime - DateTime.Now).TotalDays < 10 && eventDetails.DateTime > DateTime.Today)
                {
                    string date = eventDetails.DateTime.ToString("yyyy-MM-dd");
                    string zip = eventDetails.Venue.ZipCode;

                    // call weather api with zip and date
                    string weather = weatherObj.getWeather(eventDetails.Venue.ZipCode, eventDetails.DateTime.ToString("yyyy-MM-dd"));
                    return Ok(new { weather = weather });
                }
                return Ok(new { weather = "Can not fetch weather" });
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }

    }
}
