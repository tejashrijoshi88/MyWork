import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { VnfsComponent } from './vnfs.component';

describe('VnfsComponent', () => {
  let component: VnfsComponent;
  let fixture: ComponentFixture<VnfsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ VnfsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(VnfsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
