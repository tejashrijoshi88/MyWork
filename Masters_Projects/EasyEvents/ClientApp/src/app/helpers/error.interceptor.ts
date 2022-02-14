//File contains function to get the error received from web api call                                       
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     
import { Injectable } from '@angular/core';
import { catchError } from 'rxjs/operators';
import {
  HttpRequest,
  HttpHandler,
  HttpEvent,
  HttpInterceptor
} from '@angular/common/http';
import { Observable, throwError } from 'rxjs';

@Injectable()
export class ErrorInterceptor implements HttpInterceptor {

  constructor() { }
  // intercept to get errors
  intercept(request: HttpRequest<unknown>, next: HttpHandler): Observable<HttpEvent<unknown>> {
    return next.handle(request).pipe(catchError(err => {
      if ([401, 403, 400, 404].indexOf(err.status) !== -1) {
        console.log(err.error);
        //location.reload(true);
      }
      // send error in response
      console.log(err.status);
      const error = err.error;//.message || err.statusText;
      return throwError(err);
    }))
  }
}
