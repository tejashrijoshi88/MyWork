/**** This controller contains the API end points to give data related to authentication    ****
 **** contains methods for log in and registration od users (GET,POST)                      ****
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
    public class AuthenticationController : ControllerBase
    {
        private readonly AppDbContext dbContext;
        public AuthenticationController(AppDbContext _dbContext)
        {
            dbContext = _dbContext;
        }
        // method to check if user is registered in system
        [HttpGet]
        [Route("login")]
        public async Task<IActionResult> AuthenticateUser(string user, string password)
        {
            // get user details
            var items = await dbContext.Users.SingleOrDefaultAsync(c => c.UserName == user & c.Password == password);

            // send sussess if found
            
            if (items != null)
            {
                Response.Headers.Add("Auth", "Yes");
                return Ok(items);
            }
            else
            {
                // send 404 if not found
                Response.Headers.Add("Auth", "No");
                return NotFound("Invalid Username or Password");
            }
        }
        // method to register an user
        [HttpPost]
        [Route("register")]
        public async Task<IActionResult> CreateUser([FromBody] Users user)
        {
            // check if user with email id exists
            var email = await dbContext.Users.SingleOrDefaultAsync(c => c.EmailAddress == user.EmailAddress);
            if (email != null)
            {
                return BadRequest("User with this email id already exists");
            }
            else
            {
                // check if user with same username exists
                var username = await dbContext.Users.SingleOrDefaultAsync(c => c.UserName == user.UserName);
                if (username != null)
                {
                    return BadRequest("User Name already exists");
                }
                // create user object
                var users = new Users
                {
                    EmailAddress = user.EmailAddress,
                    FirstName = user.FirstName,
                    LastName = user.LastName,
                    Gender = user.Gender,
                    Age = user.Age,
                    UserName = user.UserName,
                    Password = user.Password,
                    Role = "User"
                };
                 // insert user data to table
                dbContext.Users.Add(users);
                await dbContext.SaveChangesAsync();
                Response.Headers.Add("role", users.Role);
                return Ok(new { message = "User created successfully" });
            }
        }
    }
}
