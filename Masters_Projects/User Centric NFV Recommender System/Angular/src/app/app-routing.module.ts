import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {VnfsComponent} from './vnfs/vnfs.component';
import {HomeComponent} from './home/home.component';

const routes: Routes = [{path:'VNFs',component:VnfsComponent},{path:'Home',component:HomeComponent}];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
