//***/ File contains type script code to show data on analysis page                                        
//**** Author - Tejashri Joshi                                                                 
//**** Date   - 12/12/2020                                                                        
import { Component, OnInit } from '@angular/core';
import { AnalysisService, EventService } from '../services';
import { ChartOptions, ChartType, ChartDataSets } from 'chart.js';
import { Color, Label } from 'ng2-charts';
import { ChartsModule, ThemeService } from 'ng2-charts';
import { first } from 'rxjs/operators';
@Component({
  selector: 'app-analysis',
  templateUrl: './analysis.component.html',
  styleUrls: ['./analysis.component.css']
})
export class AnalysisComponent implements OnInit {


  constructor(private analysisService: AnalysisService, private eventService: EventService) { }
  // delcaration of parameters
  countData: any;
  // declaration for barchart options
  barChartOptions: ChartOptions = {
    responsive: true,
  };
  barChartLabels: Label[] = [];
  barChartType: ChartType = 'bar';
  barChartLegend = true;
  events: any;
  barChartColors: Color[] = [
    {
      borderColor: 'black',
      backgroundColor: 'rgba(255,0,0,0.3)',
    },
  ];
  barChartData: ChartDataSets[];
  eventdata;
  showData = false;
  ngOnInit(): void {
    // get all events 
    this.eventService.getAllEvents().subscribe(data => { this.events = data; console.log(this.events) });
    // get analysis data for each event for bar chart
    this.analysisService.getRegistrationsPerEvent().subscribe(data => {
      this.countData = data['data'];
      //this.datalables=data['label']

      ; this.barChartLabels = data['label']
      this.barChartData = [
        { data: this.countData, label: 'Events' }
      ];
    });


  }
  // function to get analysis data for selected event
  GetEventData(e) {
    console.log(e)
    if (e != "Select EventType") {
      this.analysisService.getEventAnalysis(e).subscribe(data => {
        this.eventdata = data;
        this.showData = true;
        console.log(this.eventdata)
      });
    }

  }
}

