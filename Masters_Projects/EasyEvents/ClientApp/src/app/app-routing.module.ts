//File contains all routing end points information                                      
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {LoginComponent} from './login';
import {HomeComponent} from './home';
import {AdminComponent} from './admin';
import {AnalysisComponent} from './analysis';
import {EventsComponent} from './events';
import {RegisterComponent} from './register';
import { Role } from './models';
import { AuthGuard } from './helpers';
import { AddEventsComponent } from './addEvents';
import { DeleteEventsComponent } from './deleteEvent';
import { EventCheckinComponent } from './eventCheckin';

const routes: Routes = [{path: 'login', component: LoginComponent }
                       ,{path: 'register', component: RegisterComponent }
                       ,{path: '', component: HomeComponent,canActivate: [AuthGuard] }
                       ,{path: 'admin', component: AdminComponent,canActivate: [AuthGuard],data: { roles: [Role.Admin] }}
                       ,{path: 'analysis', component: AnalysisComponent,canActivate: [AuthGuard],data: { roles: [Role.Admin] }}
                       ,{path: 'addEvents', component: AddEventsComponent,canActivate: [AuthGuard],data: { roles: [Role.Admin] }}
                       ,{path: 'deleteEvent', component: DeleteEventsComponent,canActivate: [AuthGuard],data: { roles: [Role.Admin] }}
                       ,{path: 'eventCheckin', component: EventCheckinComponent,canActivate: [AuthGuard],data: { roles: [Role.User] }}
                       ,{path: 'events', component: EventsComponent,canActivate: [AuthGuard],data: { roles: [Role.User] } }];
@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})

export class AppRoutingModule { }
