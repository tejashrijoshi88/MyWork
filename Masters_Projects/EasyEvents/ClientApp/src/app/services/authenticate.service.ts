//File contains function to call web apis  related to login /log out                                     
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { Injectable, Inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { BehaviorSubject, Observable } from 'rxjs';
import { map } from 'rxjs/operators';
import { User } from '../models';

@Injectable({
  providedIn: 'root'
})
export class AuthenticateService {
  private currentUserSubject: BehaviorSubject<any>;
  public currentUser: Observable<User>;
  baseurl: string;
  constructor(private httpClient: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    this.currentUserSubject = new BehaviorSubject<User>(JSON.parse(localStorage.getItem('currentUser')));
    this.currentUser = this.currentUserSubject.asObservable();
    this.baseurl = baseUrl;
  }

  public get currentUserValue(): User {
    return this.currentUserSubject.value;
  }
  // function to call log in web api
  login(username: string, password: string) {


    return this.httpClient.get(this.baseurl + 'Authentication/login?user=' +
      username + "&password=" + password)
      .pipe(map(user => {
        // login successful if there's a success in response
        if (user) {

          console.log(user);
          // add user details to local storage
          localStorage.setItem('currentUser', JSON.stringify(user));
          this.currentUserSubject.next(user);
        }
        return user;
      }
      )
      );
  }
  // function to log out user
  logout() {
    // remove user from local storage to log user out
    localStorage.removeItem('currentUser');
    this.currentUserSubject.next(null);
  }
}


