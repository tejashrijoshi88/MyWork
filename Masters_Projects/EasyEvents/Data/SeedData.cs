/**** This class contains methods to insert dummy data into database tables                 ****
 **** Author - Tejashri Joshi                                                               ****
 **** Date   - 12/9/2020                                                                    ****/
using EasyEvents.Models;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace EasyEvents.Data
{
    public class SeedData
    {
        public static async Task SeedAsync(AppDbContext dbcontext)
        {
            dbcontext.Database.Migrate();
            if (!dbcontext.EventTypes.Any())
            {
                dbcontext.EventTypes.AddRange
                    (GetPreconfiguredEventTypes());
                await dbcontext.SaveChangesAsync();
            }
            if (!dbcontext.Venues.Any())
            {
                dbcontext.Venues.AddRange
                    (GetPreConfiguredVenues());
                await dbcontext.SaveChangesAsync();
            }
            if (!dbcontext.Users.Any())
            {
                dbcontext.Users.AddRange
                    (GetPreconfiguredUsers());
                await dbcontext.SaveChangesAsync();
            }
            if (!dbcontext.Events.Any())
            {
                dbcontext.Events.AddRange
                    (GetPreConfiguredEvents());
                await dbcontext.SaveChangesAsync();
            }
            if (!dbcontext.UserEvents.Any())
            {
                dbcontext.UserEvents.AddRange
                    (GetPreConfiguredUserEvents());
                await dbcontext.SaveChangesAsync();
            }

        }
        static IEnumerable<EventType> GetPreconfiguredEventTypes()
        {
            return new List<EventType>()
            {
                new EventType() { EventTypeName = "Social"},
                new EventType() { EventTypeName = "Networking" },
                new EventType() { EventTypeName = "Tech" },
                new EventType() { EventTypeName = "Travel" },
                new EventType() { EventTypeName = "Music" }
            };
        }

        static IEnumerable<Users> GetPreconfiguredUsers()
        {
            return new List<Users>()
                {
                    new Users() { UserName="omkarmkulkarni", EmailAddress="omkar7705@gmail.com", FirstName="Omkar", LastName="Kulkarni", Password="pwdIsFake",Age=32,Gender="Male",Role="User" },
                    new Users() { UserName="alberteinstein", EmailAddress="albert@einstein.com", FirstName="Albert", LastName="Einstein", Password="e=mc2",Age=32,Gender="Male",Role="User" },
                    new Users() { UserName="galileogalilei", EmailAddress="galelio@telescope.com", FirstName="Galelio", LastName="Galilei", Password="earthisround",Age=32,Gender="Male",Role="User" },
                    new Users() { UserName="tejujoshi", EmailAddress="teju2019@uw.edu", FirstName="Tejashri", LastName="Joshi", Password="Teju@2019",Age=32,Gender="Female",Role="Admin"},
                    new Users() { UserName="bhartib", EmailAddress="harti@uw.edu", FirstName="Bharti", LastName="Bansinge", Password="Bharti@2020",Age=32,Gender="Female",Role="Admin"}
                };
        }

        static IEnumerable<Venues> GetPreConfiguredVenues()
        {
            return new List<Venues>()
                {
                    new Venues() { VenueName = "Seattle Public Library", Address = "1000 Fourth Ave.", City = "Seattle", State = "WA", ZipCode = "98109", MaxCapacity = 250},
                    new Venues() { VenueName = "Four Seasons", Address = "415 Westlake Avenue North", City = "Seattle", State = "WA", ZipCode = "98109", MaxCapacity = 250},
                    new Venues() { VenueName = "Kirkland Performance Center", Address = "350 Kirkland Ave", City = "Kirkland", State = "WA", ZipCode = "98033", MaxCapacity = 400}
                };
        }

        static IEnumerable<Events> GetPreConfiguredEvents()
        {
            return new List<Events>()
                {
                    //Social
                    new Events() { HostId=4,VenueId=2,EventTypeId=5,DateTime=DateTime.ParseExact("2020-09-08","yyyy-MM-dd",null), Time="3 PM to 5 PM",Description = "Indoor/Outdoor Brunch.", EventName = "Sunday Social"},
                    new Events() { HostId=5,VenueId=1,EventTypeId=1, DateTime=DateTime.ParseExact("2020-10-01","yyyy-MM-dd",null),Time="3 PM to 5 PM", Description = "By popular demand, we're excited to be organizing our third Creators Social meetup!", EventName = "Game Night"},
                    //Networking
                    new Events() { HostId=4,VenueId=3,EventTypeId=2, DateTime=DateTime.ParseExact("2020-09-01","yyyy-MM-dd",null),Time="3 PM to 5 PM", Description = "A seminar including a series of panel discussions, key-note speakers, and networking opportunities.", EventName = "Cyber Day"},
                    new Events() { HostId=5,VenueId=1,EventTypeId=2, DateTime=DateTime.ParseExact("2020-09-01","yyyy-MM-dd",null),Time="3 PM to 5 PM", Description = "Join fellow advancement professionals for a day of networking and professional development.", EventName = "Network Roundtable"},
                    //Tech
                    new Events() { HostId=4,VenueId=3,EventTypeId=3, DateTime=DateTime.ParseExact("2020-09-01","yyyy-MM-dd",null),Time="3 PM to 5 PM", Description = "Learn how to develop AI Hardware and AI Software.", EventName = "AI Workshop" },
                    new Events() { HostId=5,VenueId=1,EventTypeId=3, DateTime=DateTime.ParseExact("2020-09-01","yyyy-MM-dd",null),Time="3 PM to 5 PM", Description = "This event is open to all tech enthusiasts of all levels.", EventName = "Hack Night"},
                   //Travel
                    new Events() { HostId=5,VenueId=1,EventTypeId=4, DateTime=DateTime.ParseExact("2020-09-01","yyyy-MM-dd",null), Time="3 PM to 5 PM",Description = "Share and discuss knowledge and best practice around innovation in tour guiding", EventName = "The National Tour Guiding Conference"},
                    //Music
                    new Events() { HostId=4,VenueId=3,EventTypeId=5, DateTime=DateTime.ParseExact("2020-09-01","yyyy-MM-dd",null),Time="3 PM to 5 PM", Description = "Learn the fundamentals of playing the guitar, strum along to popular songs and improve your understanding of music. You don't need any experience.", EventName = "Music - Guitar - 2020" }

                 };
        }
        static IEnumerable<UserEvents> GetPreConfiguredUserEvents()
        {
            return new List<UserEvents>()
                {
                    new UserEvents() {EventId=5, GuestId=1,RFIDTagId="RD000001",IsAttended="N"},
                    new UserEvents() {EventId=6, GuestId=1,RFIDTagId="RD000002",IsAttended="N"},
                    new UserEvents() {EventId=7, GuestId=1,RFIDTagId="RD000003",IsAttended="N"},
                    new UserEvents() {EventId=8, GuestId=1,RFIDTagId="RD000004",IsAttended="N"},
                    new UserEvents() {EventId=3, GuestId=1,RFIDTagId="RD000005",IsAttended="Y"},
                    new UserEvents() {EventId=1, GuestId=2,RFIDTagId="RD000006",IsAttended="N"},
                    new UserEvents() {EventId=5, GuestId=2,RFIDTagId="RD000007",IsAttended="N"},
                    new UserEvents() {EventId=2, GuestId=2,RFIDTagId="RD000010",IsAttended="N"},
                    new UserEvents() {EventId=7, GuestId=3,RFIDTagId="RD000011",IsAttended="Y"},
                    new UserEvents() {EventId=6, GuestId=3,RFIDTagId="RD000012",IsAttended="N"},
                    new UserEvents() {EventId=7, GuestId=3,RFIDTagId="RD000013",IsAttended="N"},
                    new UserEvents() {EventId=8, GuestId=3,RFIDTagId="RD000014",IsAttended="N"},
                    new UserEvents() {EventId=5, GuestId=3,RFIDTagId="RD000015",IsAttended="Y"}
               };
        }
    }
}
