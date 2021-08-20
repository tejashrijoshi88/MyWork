/**** This controller contains the API end points to give data related to venues            ****
 **** contains methods for fetching all venues and by name - (GET)                          ****
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
    public class VenuesController : ControllerBase
    {
        private readonly AppDbContext dbContext;

        public VenuesController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }

        //GET All venues
        [HttpGet]
        [Route("getAllVenues")]
        public async Task<IActionResult> getAllVenues()
        {
            try
            {
                // fetch data from database table
                var allVenues = await dbContext.Venues.ToListAsync();
                return Ok(allVenues);
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }

        // Get venue for a given name
        [HttpGet]
        [Route("getVenueByName/{venueName}")]
        public async Task<Venues> getVenueByName(string venueName)
        {
            // fetch data from database table
            var venue = await dbContext.Venues.SingleOrDefaultAsync(e => e.VenueName == venueName);
            return venue;
        }
    }
}
