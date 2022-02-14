//<!-- File contains type script code for registration page                                      
//Author - Tejashri Joshi                                                                 
//Date   - 12/10/2020     -->
import { Component, OnInit } from '@angular/core';
import { FormGroup, FormControl, FormBuilder, Validators } from '@angular/forms';
import { ComparePassword, UserNameCheck, PasswordCheck, EmailIdCheck } from '../helpers';
import { AuthenticateService, UserService } from '../services';
import { Router, ActivatedRoute } from '@angular/router';
import { Role } from '../models';
import { first } from 'rxjs/operators';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {
  // declaration of variables
  registrationForm: FormGroup;
  registrationError = false;
  error = '';

  constructor(private formBuilder: FormBuilder, private authenticationService: AuthenticateService
    , private userService: UserService
    , private route: ActivatedRoute, private router: Router) {
    // redirect to home if already logged in
    if (this.authenticationService.currentUserValue) {
      this.router.navigate(['/']);
    }
    this.registrationForm = formBuilder.group
      (
        {
          // form variables wit validations
          emailId: ['', [Validators.required, EmailIdCheck]],
          firstName: ['', Validators.required],
          lastName: [''],
          gender: ['', Validators.required],
          age: ['', Validators.required],
          userName: ['', [Validators.minLength(6)
            , Validators.required]],
          password: ['', [Validators.required
            , Validators.maxLength(15)
            , Validators.minLength(8)
            , PasswordCheck]],
          confirmPassword: ['', Validators.required

          ]
        },
        {
          validator: [ComparePassword("password", "confirmPassword")]



        }
      )
  }

  ngOnInit(): void {

  }
  // function to post the regidtration data 
  postData() {
    //console.log(this.registrationForm.value.password);
    //console.log(this.registrationForm.value.confirmPassword);
    //console.log(this.registrationForm.value);
    const registrationData = {
      "EmailAddress": this.registrationForm.value.emailId,
      "UserName": this.registrationForm.value.userName,
      "password": this.registrationForm.value.password,
      "FirstName": this.registrationForm.value.firstName,
      "LastName": this.registrationForm.value.lastName,
      "Gender": this.registrationForm.value.gender,
      "Age": Number(this.registrationForm.value.age),
      "Role": Role.User
    }

    this.userService.createUser(registrationData).pipe(first())
      .subscribe(data => { this.router.navigate(['/login']); },
        error => {
          this.registrationError = true
          this.error = error.error;
        });

  }
  // function to redirect to log in
  Redirectlogin() {
    this.router.navigate(['/login']);
  }
  // function to reset form
  resetForm() {
    this.registrationForm.reset();
    this.registrationError = false
    this.error = "";
  }


}
