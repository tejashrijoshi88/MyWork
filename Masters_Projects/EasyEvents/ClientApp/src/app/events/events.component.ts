//File contains type script code show data on my events page                                       
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { Component, OnInit } from '@angular/core';
import { AuthenticateService, EventService } from '../services';
import { User, Role } from '../models';
import { first } from 'rxjs/operators';
@Component({
  selector: 'app-events',
  templateUrl: './events.component.html',
  styleUrls: ['./events.component.css']
})
export class EventsComponent implements OnInit {
  // declaration of parameters
  futureEvents: any;
  pastEvents: any;
  selectedFutureEvent: any;
  selectedFutureEventId: any;
  selectedPastEvent: any;
  selectedPastEventId: any;
  currentUser: User;
  eventError = false;
  eventSuccess = false;
  error = '';
  isPast = false;
  isFuture = false;

  successMessage = '';
  constructor(private eventService: EventService, private authenticationService: AuthenticateService) {
    // get current user
    this.currentUser = this.authenticationService.currentUserValue;
  }

  ngOnInit(): void {
    // get future events for user
    this.eventService.getFutureEventsByUser(this.authenticationService.currentUserValue.userId).subscribe(data => { this.futureEvents = data; });
    // get past events for user
    this.eventService.getPastEventsByUser(this.authenticationService.currentUserValue.userId).subscribe(data => { this.pastEvents = data; });
  }
  // method to highlight selected event
  public highlightFutureEvent(ev) {
    this.selectedFutureEvent = ev.eventName;
    this.selectedFutureEventId = ev.eventId;
    this.isFuture = true;
    this.isPast = false;
    this.resetMessages()
  }
  // get selected past event
  public selectPastEvent(ev) {
    this.selectedPastEvent = ev.eventName;
    this.selectedPastEventId = ev.eventId;
    this.isFuture = false;
    this.isPast = true;
    this.resetMessages()

  }
  // function to reset messages
  resetMessages() {
    this.successMessage = "";
    this.eventSuccess = false;
    this.eventError = false;
    this.error = "";
  }
  // function to call service to unsubscribe the event on button click
  unsubscribeEvent() {
    // call to service
    this.eventService.unsubscribeEvent(this.currentUser.userId, this.selectedFutureEventId).pipe(first())
      .subscribe(data => { this.eventSuccess = true; this.eventError = false; this.successMessage = "You have successfully unsuscribed for the event" },
        error => {
          this.eventError = true; this.eventSuccess = false; this.error = error.error;
        });
    console.log("registered" + this.selectedFutureEventId)
  }
}
