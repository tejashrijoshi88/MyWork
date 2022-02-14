//***/ File contains type script code to show data on delete events page                                       
//**** Author - Tejashri Joshi                                                                 
//**** Date   - 12/12/2020                                                                        
import { Component, OnInit } from '@angular/core';
import { EventService } from '../services';
import { first } from 'rxjs/operators';
@Component({
  selector: 'deleteEvent-admin',
  templateUrl: './deleteEvent.component.html',
  styleUrls: ['./deleteEvent.component.css']
})
export class DeleteEventsComponent implements OnInit {
  // declaration of parameters
  selectedEvent: any;
  selectedEventId: any;
  events: any;
  eventError = false;
  eventSuccess = false;
  error = '';
  successMessage = '';
  constructor(private eventService: EventService) {

  }
  ngOnInit(): void {
    // get all events 
    this.eventService.getAllEvents().subscribe(data => { this.events = data; console.log(this.events) });
  }
  // function to highlight selected event
  public highlightEvent(ev) {
    this.selectedEvent = ev.eventName;
    this.selectedEventId = ev.eventId;
    this.resetMessages();
  }
  // funtion to reset messages
  resetMessages() {
    this.eventError = false
    this.eventSuccess = false
    this.error = "";
    this.successMessage = "";
  }
  // function to call service to delete selected event
  deleteEvent() {
    this.eventService.deleteEvents(this.selectedEventId).pipe(first())
      .subscribe(data => { this.eventSuccess = true; this.eventError = false; this.successMessage = "Event deleted successfully" },
        error => {
          this.eventError = true; this.eventSuccess = false; this.error = error.error;
        });
    //console.log("registered"+this.selectedEventId)
  }
}
