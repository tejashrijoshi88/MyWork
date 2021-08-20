import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HttpClientModule} from '@angular/common/http';
import {FormsModule,ReactiveFormsModule} from '@angular/forms';
import { VnfsComponent } from './vnfs/vnfs.component';
import { HomeComponent } from './home/home.component';
import {SidebarModule} from 'ng-sidebar';
import {DragDropModule} from '@angular/cdk/drag-drop';
import {NgxGaugeModule } from 'ngx-gauge';

@NgModule({
  declarations: [
    AppComponent,
    VnfsComponent,
    HomeComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule,
    ReactiveFormsModule,
    SidebarModule.forRoot(),
    DragDropModule,NgxGaugeModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
