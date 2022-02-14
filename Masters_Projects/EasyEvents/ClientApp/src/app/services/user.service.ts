//File contains function to call web apis related to registration                                      
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { Injectable, Inject } from '@angular/core';
import { HttpClient,HttpHeaders } from '@angular/common/http';
import { User } from '../models';
@Injectable({
  providedIn: 'root'
})
export class UserService {
  baseurl: string;
  constructor(private httpClient: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    this.baseurl = baseUrl;
  }
  // create user by registration
  createUser(registrationDetails){
    //http post call
    console.log(registrationDetails);
    const httpHeaders = new HttpHeaders({'Content-Type': 'application/json; charset=utf-8'});
    
    return this.httpClient.post(this.baseurl+'Authentication/register', registrationDetails, { headers: httpHeaders });
  }
}
