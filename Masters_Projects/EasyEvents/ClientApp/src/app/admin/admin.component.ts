//***/ File contains type script code for admin option                                        
//**** Author - Tejashri Joshi                                                                 
//**** Date   - 12/12/2020                                                                        
import { Component, OnInit } from '@angular/core';
import { FormGroup, FormControl, FormBuilder, Validators } from '@angular/forms';
import { AuthenticateService, EventService } from '../services';
import { Router, ActivatedRoute } from '@angular/router';
import { Role } from '../models';
import { first } from 'rxjs/operators';
@Component({
  selector: 'app-admin',
  templateUrl: './admin.component.html',
  styleUrls: ['./admin.component.css']
})
export class AdminComponent implements OnInit {

  constructor(private formBuilder: FormBuilder
    , private authenticationService: AuthenticateService
    , private eventService: EventService
    , private route: ActivatedRoute, private router: Router) {

  }
  ngOnInit(): void {

  }

}
