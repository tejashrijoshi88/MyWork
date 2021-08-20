//File contains code to check if user is authorised to see the web page as per his role                                    
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     
import { Injectable } from '@angular/core';
import { CanActivate, ActivatedRouteSnapshot, RouterStateSnapshot, Router } from '@angular/router';
import { Observable } from 'rxjs';
import {AuthenticateService} from '../services';

@Injectable({
  providedIn: 'root'
})
export class AuthGuard implements CanActivate {
  constructor(private authenticateService:AuthenticateService
             ,private router:Router){}
  canActivate(
    route: ActivatedRouteSnapshot,
    state: RouterStateSnapshot)
    {
      const currentUser = this.authenticateService.currentUserValue;
      if (currentUser)
      {
                    // check if route is restricted by role
                    if (route.data.roles && route.data.roles.indexOf(currentUser.role) === -1) {
                      // role not authorised so redirect to home page
                      this.router.navigate(['/']);
                      return false;
                  
      }
      //authorised user
      return true;
  }
          // not logged in so redirect to login page with the return url
          this.router.navigate(['/login'], { queryParams: { returnUrl: state.url } });
          return false;
}
}
