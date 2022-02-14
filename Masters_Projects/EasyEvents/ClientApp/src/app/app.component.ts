//File contains function handle logic for menues on home and landing pages                                    
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { Component } from '@angular/core';
import { Router } from '@angular/router';

import { AuthenticateService } from './services';
import { User, Role } from './models';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  currentUser: User;
  constructor(private router: Router,
    private authenticateService: AuthenticateService){
      this.authenticateService.currentUser.subscribe(x => this.currentUser = x);
  }
  get isAdmin() {
    //console.log(this.currentUser.role);
    return this.currentUser && this.currentUser.role === Role.Admin;
  }
  get isUser() {
      //console.log(this.currentUser.role);
      return this.currentUser && this.currentUser.role === Role.User;
  }
// function call to log out
logout() {
  this.authenticateService.logout();
  this.router.navigate(['/login']);
}
}
