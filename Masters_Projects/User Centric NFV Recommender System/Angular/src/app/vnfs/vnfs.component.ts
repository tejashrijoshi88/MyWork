/*  Author - Tejashri Joshi
 Date - 10-20-2020
This file contains methods which are called from html */
import { Component, OnInit } from '@angular/core';
import { VnfService } from './vnfs.service';
import { FormGroup, FormControl, Validators,FormBuilder,FormArray} from '@angular/forms';
import {CdkDragDrop,moveItemInArray,transferArrayItem,copyArrayItem} from '@angular/cdk/drag-drop';

@Component({
  selector: 'app-vnfs',
  templateUrl: './vnfs.component.html',
  styleUrls: ['./vnfs.component.css']
})
export class VnfsComponent implements OnInit {

  constructor(public vnfService:VnfService,private formBuilder: FormBuilder) {}
  // declaration of variables
  NFVServiceform:FormGroup;
  QoSValue;
  vnfList:any;
  filteredVnf:any;
  QoSList:any;
  QoSValues:any;
  NFVRank:string;
  VNFQoSList=[];
  description;
  difference:Number;
  prevNFVValue:string;
  currNFVValue:Number;
  done=[];
  gaugeType ;
  gaugeValue ;
  gaugeLabel ;
  gaugeAppendText;
  min;
  max;
  duration;
  thick;
  thresholdConfig;
  QoSWeightCases = ['lt-Centric', 'rt-Centric', 'tp-Centric','av-Centric','rl-Centric','Other'];
  

  ngOnInit(): void {
    // add controls to from
    this.NFVServiceform = this.formBuilder.group
    ({selectQoS: new FormControl(),
      QoSValue:new FormControl(),
      selectScenario:new FormControl()
    });
    // get list vnf list from database
    this.vnfService.getVnfs().subscribe(data=>{this.vnfList=data['vnf'];this.filteredVnf=this.vnfList;})
    // get QoS list from database
    this.vnfService.getAllQoS("Other").subscribe(data=>{this.QoSList=data["name"];this.QoSValues=data["value"];});
    // initialize parameters for gauge
    this.gaugeType="semi"; 
    this.NFVRank='0';
    this.description="No VNF Selected";
    this.gaugeLabel ="Performance Score" ;
    this.gaugeAppendText="";
    this.min=0;
    this.max=1;
    this.duration=1000;
    this.thick=10;
    this.prevNFVValue='0';
    this.difference=0;
    this.thresholdConfig = {
      '0': {color: 'red'},
      '0.4': {color: 'orange'},
      '0.7': {color: 'green'}
  };
  }
  // method gets called when item dragged from list
  drop(event: CdkDragDrop<string[]>) {
    if (event.previousContainer !== event.container)
    {
      copyArrayItem(event.previousContainer.data,
                    event.container.data,
                    event.previousIndex,
                    event.currentIndex);
    }
    this.submit();
  }
  // this method collects the user selected data and submit to POST and show result
  submit(){
    console.log(this.done);
    var formData= new FormData();
    for (var i in this.done)
    {
      formData.append('VNF'+i,this.done[i]);
    };
    if (this.VNFQoSList.length<5)
    {
      alert("Please provide values for all QoS parameters");
    }
    else{
    for (let i of this.VNFQoSList)
    {formData.append(i.vnfName,i.qosvalue);}
    }
    this.vnfService.postVnfData(formData).subscribe(data=>{this.NFVRank=data['name'];
    
    this.difference= Number(this.prevNFVValue) - Number(this.NFVRank); 
    var percentage=String((Math.abs(Number(this.difference))*100)/Number(this.prevNFVValue));
   
    if (this.prevNFVValue !='0')
    {
      
      if (this.difference < 0)
      {
        this.description="The performance Score increased by "+percentage+"%";
      }
      else if(this.difference > 0)
      {
      this.description="The performance Score decreased by "+percentage+"%";
      }
      else  
      {
        this.description="There is no change in performance Score";
      }
      
    }
    else{this.description="First VNF selected";}
    this.prevNFVValue=this.NFVRank;
  });    
  }

  // this method clears the selected VNF list
  clearList()
  {
    this.done = [];
    this.NFVRank='0';
    this.description="No VNF Selected";
    this.prevNFVValue='0';
    this.difference=0;
    
  }
  // method gets called on item removal from selected VNF list
  removeItem(index: number){

    this.done.splice(index, 1);
    if(this.done.length!=0)
    {
      this.submit();
    }
    else
    {
      this.NFVRank='0';
      this.description="No VNF Selected";
      this.prevNFVValue='0';
      this.difference=0;
    }
  }
  // this method gets called when user select QoS value from drop down
  changeQoS(e) {
    this.NFVServiceform.patchValue({selectQoS:e.target.value});
  }
  // this method gets called when user select scenario from drop down
  changeScenario(e) {
    
    this.NFVServiceform.patchValue({selectScenario:e.target.value});
    //console.log("inside changescenario"+e.target.value);
    this.VNFQoSList=[];
    if(this.NFVServiceform.get("selectScenario").value!="Other")
    {
    this.vnfService.getAllQoS(e.target.value).subscribe(data=>{
      this.QoSList=data["name"];this.QoSValues=data["value"];
      for (var i in this.QoSList)  
      {
        //console.log(this.QoSList[i],this.QoSValues[i]); 
        this.VNFQoSList.push({vnfName:this.QoSList[i],qosvalue:this.QoSValues[i]});
      }
    }); 
   }
    
  }
  // this method gets called on add QoS value to QoS list
  addToList(){
    var total=0;
    this.QoSValue=this.NFVServiceform.get("QoSValue").value;
    console.log(this.NFVServiceform.get("selectQoS").value);
    this.VNFQoSList.push({vnfName:this.NFVServiceform.get("selectQoS").value,qosvalue:this.NFVServiceform.get("QoSValue").value});
    for (let i of this.VNFQoSList) 
    {
      total=total+Number(i.qosvalue);
      if (total>1)
      {
        alert("Total Weights should not exceed 1");
      }
    }
  }
  // method to clear QoS list
  clearQoSList(){
    this.VNFQoSList=[];
    this.NFVServiceform.patchValue({QoSValue:null});
  }
  // method to search the VNF from list
  searchVNF(e)
  {
    if(e.target.value !="")
    {
    let newList = this.vnfList.filter(function(obj){
        //check if object value contains value you are looking for
        if(obj.toLowerCase().includes((e.target.value).toLowerCase())){
          //add this object to the filtered array
          return obj; 
          }
         }
        );
        this.filteredVnf=newList;
  }
  else{
    this.filteredVnf=this.vnfList;
  }
}

}
