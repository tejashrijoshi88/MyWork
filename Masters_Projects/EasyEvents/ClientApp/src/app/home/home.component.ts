//File contains type script code show data on home                                       
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { Component, OnInit } from '@angular/core';
import { FormGroup, FormControl, FormBuilder, Validators } from '@angular/forms';
import { AuthenticateService, EventService } from '../services';
import { User, Role } from '../models';
import { ActivatedRoute, Router } from '@angular/router';
import { first } from 'rxjs/operators';
@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {
  // declaration of parameters
  selectedEvent: any;
  selectedEventId: any;
  selectedEventName: any
  eventtypes: any;
  loading = false;
  currentUser: User;
  events: any;
  rfid: any;
  eventError = false;
  eventSuccess = false;
  checkWeatherFlag = false;
  showHoliday = false;
  error = '';
  successMessage = '';
  weather: any;
  holidays: any;
  constructor(private formBuilder: FormBuilder
    , private authenticationService: AuthenticateService
    , private eventService: EventService
    , private route: ActivatedRoute, private router: Router) {
    this.currentUser = this.authenticationService.currentUserValue;
  }

  ngOnInit(): void {
    // get eveny types
    this.eventService.getEventTypes().subscribe(data => { this.eventtypes = data; });
    // get all events
    this.eventService.getAllEvents().subscribe(data => { this.events = data; console.log(this.events) });


  }
  // function to filer events by type
  GetEventsByType(e) {
    this.resetMessages();
    if (e != "Select Event") {
      this.eventService.getEventsByType(e).subscribe(data => { this.events = data; console.log(this.events) });
    }
    console.log(e);
  }
  // function to filter events by name string
  GetEventsByName() {
    //this.selectedEventName=e.target.value
    this.resetMessages();
    this.selectedEventName = (<HTMLInputElement>document.getElementById("selectEventName")).value;
    this.eventService.getEventsByName(this.selectedEventName).subscribe(data => { this.events = data; console.log(this.events) });
    console.log(this.selectedEventName);
  }
  // function to reset messages
  resetMessages() {
    this.eventError = false
    this.eventSuccess = false
    this.error = "";
    this.successMessage = "";
    this.checkWeatherFlag = false;
    this.showHoliday = false;
  }
  // function to clear filer
  ClearFiler() {
    this.eventService.getAllEvents().subscribe(data => { this.events = data; console.log(this.events) });
    this.resetMessages();
    //(<HTMLInputElement>document.getElementById("selectEventName")).innerHTML = "";
  }
  // check if user is admin
  get isAdmin() {
    return this.currentUser && this.currentUser.role === Role.Admin;
  }
  // check if user is not admin
  get isUser() {
    return this.currentUser && this.currentUser.role === Role.User;
  }
  // function to highlight event
  public highlightEvent(ev) {
    this.selectedEvent = ev.eventName;
    this.selectedEventId = ev.eventId;

    this.resetMessages();
  }
  // function call on check weather button
  CheckWeather() {
    this.eventService.getWeather(this.selectedEventId).pipe(first()).subscribe(data => { this.weather = data; this.checkWeatherFlag = true },
      error => {
        this.eventError = true; this.eventSuccess = false; this.error = error;
      });
  }
  // function call on show holiday list
  ShowHolidays() { this.eventService.getHoliday().subscribe(data => { this.holidays = data; this.showHoliday = true; console.log(this.holidays) }); }
  //method call for register for the event
  registerEvent() {
    const userEventData = { "EventId": this.selectedEventId, "GuestId": this.currentUser.userId }
    this.eventService.signUpEvent(userEventData).pipe(first())
      .subscribe(data => { this.rfid = data; this.eventSuccess = true; this.eventError = false; this.successMessage = "You subscribed to the event successfully. Your RFIdtag is " },
        error => {
          this.eventError = true; this.eventSuccess = false; this.error = error.error;
        });
    console.log("registered" + this.selectedEventId)
  }
}
