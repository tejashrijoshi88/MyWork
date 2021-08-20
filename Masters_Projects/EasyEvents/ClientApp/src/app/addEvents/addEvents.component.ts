//***/ File contains type script code to show data on add events page                                        
//**** Author - Tejashri Joshi                                                                 
//**** Date   - 12/12/2020                                                                        
import { Component, OnInit } from '@angular/core';
import { FormGroup, FormControl, FormBuilder, Validators } from '@angular/forms';
import { AuthenticateService,EventService } from '../services';
import { Router, ActivatedRoute } from '@angular/router';
import { Role } from '../models';
import { first } from 'rxjs/operators';
@Component({
  selector: 'addEvents-admin',
  templateUrl: './addEvents.component.html',
  styleUrls: ['./addEvents.component.css']
})
export class AddEventsComponent implements OnInit {
  // set parameters
    eventForm: FormGroup;
    eventError = false;
    eventSuccess = false;
    error = '';
    successMessage = '';
    eventtypes:any;
    venues:any;
  constructor(private formBuilder: FormBuilder
    ,private authenticationService: AuthenticateService
    ,private eventService: EventService
    ,private route: ActivatedRoute,private router: Router) 
    { 
      // declare form variables
        this.eventForm = formBuilder.group
        (
          {
            eventName: ['', Validators.required],
            description: [''],
            EventType: ['',Validators.required],
            venue: ['', Validators.required],
            Datetime: ['', Validators.required],
            timing: ['', Validators.required]
            },
        )
    }
  ngOnInit(): void {
    // get event types by calling service
    this.eventService.getEventTypes().subscribe(data => {this.eventtypes=data;});
    // get venues by calling service
    this.eventService.getVenues().subscribe(data => {this.venues=data;});
  }
  // function to get user selected event type
  changeEventType(e){   
    console.log(e.target.value);
    this.eventForm.patchValue({EventType:e.target.value});
}
 // function to get user selected venue
changeVenue(e){
  console.log(e.target.value);
  this.eventForm.patchValue({venue:e.target.value});
}
 // function to post event data to backend
postData() {
  console.log(this.eventForm.value);
  const registrationData = {"EventName":this.eventForm.value.eventName,
                            "DateTime": this.eventForm.value.Datetime, 
                            "Time": this.eventForm.value.timing, 
                            "Description": this.eventForm.value.description,
                            "EventType":this.eventForm.value.EventType,
                            "HostId":this.authenticationService.currentUserValue.userId,
                            "Venue":this.eventForm.value.venue,
                            }
 // call service to post data
  this.eventService.createEvent(registrationData).pipe(first())
    .subscribe(data => { this.eventForm.reset(); this.eventSuccess = true;this.eventError=false;this.successMessage = 'Event created successfully';},
    error => {this.eventError=true;
              this.eventSuccess=false;
              this.error = error.error;
    });
}
// function to reset form 
resetForm() {
  console.log("i am in reset");
  this.eventForm.reset();
  this.eventError = false;
  this.eventSuccess = false;
  this.error = "";
  this.successMessage = "";
}
}
