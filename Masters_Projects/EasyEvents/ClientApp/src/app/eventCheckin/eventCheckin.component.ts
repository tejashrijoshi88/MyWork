//File contains type script code to show data on event checkin page                                       
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     
import { Component, OnInit } from '@angular/core';
import { EventService } from '../services';
import { first } from 'rxjs/operators';
import { FormGroup, FormControl, FormBuilder, Validators } from '@angular/forms';
import { Router, ActivatedRoute } from '@angular/router';
@Component({
    selector: 'eventCheckin-admin',
    templateUrl: './eventCheckin.component.html',
    styleUrls: ['./eventCheckin.component.css']
  })
  export class EventCheckinComponent implements OnInit {
    // declaration of parameters
    checkinForm: FormGroup;
    successMessage:any;
    error:any;
    eventError:any;
    eventSuccess:any;
    constructor(private eventService: EventService,private formBuilder: FormBuilder) 
    { 
      this.checkinForm = formBuilder.group
      (
        {
          RFID: ['', [Validators.required]]
        }
      )
    }
  ngOnInit(): void {
    
  }
  // function to call service to post data of RFID
  postData(){
    this.eventService.postEventCheckin(this.checkinForm.value.RFID).subscribe(data => {console.log(this.successMessage)},
      error => {if(error.status==200)
                {
                  console.log("sdsf");
                  this.eventError=false;
                  this.eventSuccess=true;
                  this.successMessage="CheckIn Successfull";
                }
                if (error.status==404)
                {
                  this.eventSuccess=false;
                  this.eventError=true;
                  this.error="You have not signed up for the event";
                }
                if (error.status==400)
                {
                  this.eventSuccess=false;
                  this.eventError=true;
                  this.error="Event is either past event or you are checking up early..Check in start before 24 hrs of event day";
                };
        });
  }
  }