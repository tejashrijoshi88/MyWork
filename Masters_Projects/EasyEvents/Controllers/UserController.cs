/**** This controller contains the API end points to give data related to users             ****
 **** contains methods to fetch data for all users and by Id  (GET)                         ****
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
    public class UserController : ControllerBase
    {
        private readonly AppDbContext dbContext;

        public UserController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }

        // Get user for a given user id
        [HttpGet]
        [Route("getUserById/{UserId}")]
        public async Task<Users> getUserById(int UserId)
        {
            // fetch data from database
            var user = await dbContext.Users.SingleOrDefaultAsync(e => e.UserId == UserId);
            return user;
        }

        //GET All users
        [HttpGet]
        [Route("getAllUsers")]
        public async Task<IActionResult> getAllUsers()
        {
            try
            {
                // fetch data from database
                var allUsers = await dbContext.Users.ToListAsync();
                // added custom header
                Response.Headers.Add("UserCount", allUsers.Count.ToString());
                return Ok(allUsers);
            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }
        }
    }
}
