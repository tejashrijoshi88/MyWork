// Author - Tejashri Joshi
// Date - 10-15-2020
// This file contains the call to the REST APIs developed in python 
import { Injectable } from '@angular/core';
import { HttpClient,HttpHeaders } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class VnfService {

  constructor(private httpClient:HttpClient) { }
  getVnfs(){
    return this.httpClient.get('http://localhost:5000/VNF');
  }
  getAllQoS(scenario){
    return this.httpClient.get('http://localhost:5000/QoS/'+scenario);
  }
  postVnfData(vnfQoS){
    //const httpHeaders = new HttpHeaders({'Content-Type': 'application/json'});
    return this.httpClient.post('http://localhost:5000/perfScore',vnfQoS);//,{headers:httpHeaders});
  }
}

