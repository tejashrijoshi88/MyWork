//File contains function to call web apis related to analysis                                      
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
export class AnalysisService {
  private currentUserSubject: BehaviorSubject<any>;
  public currentUser: Observable<User>;
  baseurl: string;
  constructor(private httpClient: HttpClient, @Inject('BASE_URL') baseUrl: string) { 
    this.baseurl = baseUrl;
  }
  // function to call web api to get registration count per event
  getRegistrationsPerEvent(){

    return this.httpClient.get(this.baseurl+'EventAnalysis/getRegistrationPerEvent');
  }
    // function to call web api to get analysis for given event
  getEventAnalysis(eventName){

    return this.httpClient.get(this.baseurl+'EventAnalysis/getEventAnalysis/'+eventName);
  }
}


