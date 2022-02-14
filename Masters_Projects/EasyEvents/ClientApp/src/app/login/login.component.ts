//<!-- File contains type script code for log in page                                      
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { Router, ActivatedRoute } from '@angular/router';

import { first } from 'rxjs/operators';
import { User } from '../models';
import { AuthenticateService } from '../services/authenticate.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {
  // declare parameters
  loginForm: FormGroup;
  loading = false;
  submitted = false;
  returnUrl: string;
  error = '';
  public currentUser:any;
  constructor(private formBuilder: FormBuilder
             ,public authenticate:AuthenticateService
             ,private route: ActivatedRoute
             ,private router: Router) {        
               // redirect to home if already logged in
              if (this.authenticate.currentUserValue) { 
                  this.router.navigate(['/']);
              } }

  ngOnInit(): void {
    // form variables
    this.loginForm = this.formBuilder.group({
      username: ['', Validators.required],
      password: ['', Validators.required]
  });
  }
    // convenience getter for easy access to form fields
    get f() { return this.loginForm.controls; }

    onSubmit() {
      this.submitted = true;

      // stop here if form is invalid
      if (this.loginForm.invalid) {
          return;
      }
      this.loading = true;
      console.log("calling service");
      // call service to check user
      this.authenticate.login(this.f.username.value, this.f.password.value)
          .subscribe(
              data => {
                  this.router.navigate(['/']);
              },
              error => {console.log(error.error);
                  this.error = error.error;
                  this.loading = false;
              });
}
// navigate to registration page
register(){
  this.router.navigate(['/register']);
}
}
