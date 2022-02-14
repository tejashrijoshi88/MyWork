/**** This controller contains the API end points integrate the external existing services      ****
 **** Methods contain service to send email,service to get holiday list and service for weather ****
 **** cThese end points are called from diferent controllers                                    ****
 **** response shared is in json format for these end points                                    ****
 **** Author - Tejashri Joshi                                                                   ****
 **** Date   - 12/9/2020                                                                        ****/
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using Mailjet.Client;
using Mailjet.Client.Resources;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace EasyEvents.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class ExternalServicesController : ControllerBase
    {
        // helper method to request web service and get response
        [NonAction]
        public string RequestService(string url)
        {
            // prepare the http request
            WebRequest serviceRequest = (WebRequest)WebRequest.Create(url);
            // identify the method of HTTP Request as GET
            serviceRequest.Method = "GET";
            // adding headers to call the service
            serviceRequest.ContentLength = 0;
            serviceRequest.ContentType = "application/json";
            // header values for api key is taken as service headers
            serviceRequest.Headers.Add("x-rapidapi-key", "60b5a7715fmsh3c472294b45b07dp1dfa9bjsnd236047cde7a");
            // establish a connection and retrieve the HTTP response message
            WebResponse serviceResponse = (WebResponse)serviceRequest.GetResponse();
            // read response data stream
            Stream receiveStream = serviceResponse.GetResponseStream();
            // properly set the encoding as utf-8
            Encoding encode = System.Text.Encoding.GetEncoding("utf-8");
            // encode the stream using utf-8
            StreamReader readStream = new StreamReader(receiveStream, encode, true);
            // read the entire stream ans store in service result
            String serviceResult = readStream.ReadToEnd();
            return serviceResult;
        }
        // helper method to get weather for given zip and date
        [HttpGet]
        [Route("getWeather")]
        public string getWeather(string zip, string date)
        {
            try
            {
                // identifies the service end point for service provider 1 (SP1)
                var serviceURL = "https://weatherapi-com.p.rapidapi.com/forecast.json?q=" + zip + "&days=1&dt=" + date;
                string serviceResult = RequestService(serviceURL);
                // convert result into json object
                var json = JObject.Parse(serviceResult);
                // get continent name 
                string maxtempinF = json.SelectToken("forecast..forecastday[0].day..maxtemp_f").ToString();
                string mintempinF = json.SelectToken("forecast..forecastday[0].day..mintemp_f").ToString();
                string status = json.SelectToken("forecast..forecastday[0].day..condition..text").ToString();
                return "Max Temperature in F : " + maxtempinF + " Min Temperature in F : " + mintempinF + " Status : " + status;
            }
            catch (Exception e)
            {
                return "Exception" + e.Message;
            }
        }
        // service end point to get holiday list from eisting api
        [HttpGet]
        [Route("getHolidayList")]
        public async Task<IActionResult> getHolidayList()
        {
            try
            {
                // identifies the service end point for service provider 
                var serviceURL = "https://public-holiday.p.rapidapi.com/2020/US";
                // method call to get response 
                string serviceResult = RequestService(serviceURL);
                return Ok(serviceResult);
            }
            catch (Exception e)
            {
                return BadRequest("Exception" + e.Message);
            }
        }
        // helper method to send email to user defined as input parameters
        [HttpGet]
        [Route("sendEmail")]
        public async Task SendEmail(string emailId,string firstName,string eventName,string action)
        {
            //MailjetClient client = new MailjetClient(Environment.GetEnvironmentVariable("MJ_APIKEY_PUBLIC"), Environment.GetEnvironmentVariable("MJ_APIKEY_PRIVATE"));
            // created object with required keys and add all other parameters
            MailjetClient client = new MailjetClient("2946db6b27a9f2d02583fd29e972553d", "3baa0be00212cb6193dd2c281122896e");
            MailjetRequest request = new MailjetRequest { Resource = Send.Resource, }
            .Property(Send.FromEmail, "bhartib@uw.edu")
            .Property(Send.FromName, "TCSS 559 Group 9")
            .Property(Send.Subject, "Easy Events - Event Registration")
            .Property(Send.TextPart, "Registration Successfull")
            .Property(Send.HtmlPart, "<h3>Dear " + firstName + ", <br /> You have successfully "+action+" for event " + eventName+ ".<br /> Thanks,<br />Easy Events Team")//body of email
            .Property(Send.Recipients, new JArray {new JObject {{"Email", emailId} }});//add receiver email 
            MailjetResponse response = await client.PostAsync(request);
            if (response.IsSuccessStatusCode)
            {
            Console.WriteLine(string.Format("Total: {0}, Count: {1}\n", response.GetTotal(), response.GetCount()));
            Console.WriteLine(response.GetData());
            }
            else
            {
            Console.WriteLine(string.Format("StatusCode: {0}\n", response.StatusCode));
            Console.WriteLine(string.Format("ErrorInfo: {0}\n", response.GetErrorInfo()));
            Console.WriteLine(string.Format("ErrorMessage: {0}\n", response.GetErrorMessage()));
            }
        }
    }
}
