import { Component, OnInit } from '@angular/core';
import { VnfService } from '../vnfs/vnfs.service';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {

  constructor(public vnfService:VnfService) { }
  NFVs:[];
  ngOnInit(): void {
        
  }


}
