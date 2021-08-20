//File contains information of all modules created in project                                    
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     -->
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { LoginComponent } from './login/login.component';
import { ReactiveFormsModule } from '@angular/forms';
import { HttpClientModule, HTTP_INTERCEPTORS } from '@angular/common/http';
import { HomeComponent } from './home/home.component';
import { AdminComponent } from './admin/admin.component';
import { EventsComponent } from './events/events.component';
import { AnalysisComponent } from './analysis/analysis.component';
import { RegisterComponent } from './register/register.component';
import {AddEventsComponent} from './addEvents';
import {DeleteEventsComponent} from './deleteEvent';
import {EventCheckinComponent} from './eventCheckin';
import {ErrorInterceptor} from './helpers';
import { ChartsModule ,ThemeService } from 'ng2-charts';

@NgModule({
  declarations: [
    AppComponent,
    LoginComponent,
    HomeComponent,
    AdminComponent,
    EventsComponent,
    AnalysisComponent,
    RegisterComponent,
    AddEventsComponent,
    DeleteEventsComponent,
    EventCheckinComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ReactiveFormsModule,
    HttpClientModule,
    ChartsModule,
  ],
  providers: [ { provide: HTTP_INTERCEPTORS,useClass: ErrorInterceptor, multi: true },ThemeService],

  bootstrap: [AppComponent]
})
export class AppModule { }
