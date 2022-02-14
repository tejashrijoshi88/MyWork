//File contains function to call web apis related to events                                      
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { Inject, Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class EventService {
  baseurl: string;
  constructor(private httpClient: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    this.baseurl = baseUrl;
  }
  // web api call to create event
  createEvent(eventDetails) {
    //http post call
    console.log(eventDetails);
    const httpHeaders = new HttpHeaders({ 'Content-Type': 'application/json; charset=utf-8' });

    return this.httpClient.post(this.baseurl + 'Event/addEvent', eventDetails, { headers: httpHeaders });
  }
  // web api call to delete event
  deleteEvents(eventId) {
    return this.httpClient.delete(this.baseurl + 'Event/cancleEvent/' + eventId);
  }
  // web api call to get all event
  getAllEvents() {
    return this.httpClient.get(this.baseurl + 'Event/getAllEvents');
  }
  // web api call to get event by type
  getEventsByType(type) {
    return this.httpClient.get(this.baseurl + 'Event/getEvent/byType/' + type);
  }
  // web api call to get event by name
  getEventsByName(name) {
    return this.httpClient.get(this.baseurl + 'Event/getEvent/byName/' + name);
  }
  // web api call to get event types
  getEventTypes() {
    return this.httpClient.get(this.baseurl + 'EventType/getAllEventTypes');
  }
  // web api call to get venues
  getVenues() {
    return this.httpClient.get(this.baseurl + 'Venues/getAllVenues');
  }
  // web api call to get future events for user
  getFutureEventsByUser(userId) {
    return this.httpClient.get(this.baseurl + 'UserEvents/allEvents/future/' + userId);
  }
  // web api call to get past events for user
  getPastEventsByUser(userId) {
    return this.httpClient.get(this.baseurl + 'UserEvents/allEvents/past/' + userId);
  }
  // web api call to signup for event
  signUpEvent(ueDetails) {
    const httpHeaders = new HttpHeaders({ 'Content-Type': 'application/json; charset=utf-8' });
    return this.httpClient.post(this.baseurl + 'UserEvents/insertUserEvent', ueDetails, { headers: httpHeaders });
  }
  // web api call to unsubscribe for event
  unsubscribeEvent(userId, eventId) {

    return this.httpClient.delete(this.baseurl + 'UserEvents/cancleEventSignUp/' + userId + "/" + eventId);
  }
  // web api call to get weather for event day
  getWeather(eventId) {

    return this.httpClient.get(this.baseurl + 'Event/getWeather/' + eventId);
  }
  // web api call to get holiday list
  getHoliday() {

    return this.httpClient.get(this.baseurl + 'ExternalServices/getHolidayList');
  }
  // web api call to post event check in by user
  postEventCheckin(RFID) {
    const httpHeaders = new HttpHeaders({ observe: 'body', responseType: 'xml' });
    return this.httpClient.put<string>(this.baseurl + 'EventCheckin/updateUserEvent/' + RFID, { headers: httpHeaders });
  }
}
