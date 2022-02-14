(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["main"],{

/***/ "./$$_lazy_route_resource lazy recursive":
/*!******************************************************!*\
  !*** ./$$_lazy_route_resource lazy namespace object ***!
  \******************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

function webpackEmptyAsyncContext(req) {
	// Here Promise.resolve().then() is used instead of new Promise() to prevent
	// uncaught exception popping up in devtools
	return Promise.resolve().then(function() {
		var e = new Error("Cannot find module '" + req + "'");
		e.code = 'MODULE_NOT_FOUND';
		throw e;
	});
}
webpackEmptyAsyncContext.keys = function() { return []; };
webpackEmptyAsyncContext.resolve = webpackEmptyAsyncContext;
module.exports = webpackEmptyAsyncContext;
webpackEmptyAsyncContext.id = "./$$_lazy_route_resource lazy recursive";

/***/ }),

/***/ "./src/app/app-routing.module.ts":
/*!***************************************!*\
  !*** ./src/app/app-routing.module.ts ***!
  \***************************************/
/*! exports provided: AppRoutingModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppRoutingModule", function() { return AppRoutingModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/__ivy_ngcc__/fesm2015/core.js");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/__ivy_ngcc__/fesm2015/router.js");
/* harmony import */ var _vnfs_vnfs_component__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./vnfs/vnfs.component */ "./src/app/vnfs/vnfs.component.ts");
/* harmony import */ var _home_home_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./home/home.component */ "./src/app/home/home.component.ts");






const routes = [{ path: 'VNFs', component: _vnfs_vnfs_component__WEBPACK_IMPORTED_MODULE_2__["VnfsComponent"] }, { path: 'Home', component: _home_home_component__WEBPACK_IMPORTED_MODULE_3__["HomeComponent"] }];
class AppRoutingModule {
}
AppRoutingModule.ɵmod = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdefineNgModule"]({ type: AppRoutingModule });
AppRoutingModule.ɵinj = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdefineInjector"]({ factory: function AppRoutingModule_Factory(t) { return new (t || AppRoutingModule)(); }, imports: [[_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"].forRoot(routes)], _angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"]] });
(function () { (typeof ngJitMode === "undefined" || ngJitMode) && _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵsetNgModuleScope"](AppRoutingModule, { imports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"]], exports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"]] }); })();
/*@__PURE__*/ (function () { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵsetClassMetadata"](AppRoutingModule, [{
        type: _angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"],
        args: [{
                imports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"].forRoot(routes)],
                exports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"]]
            }]
    }], null, null); })();


/***/ }),

/***/ "./src/app/app.component.ts":
/*!**********************************!*\
  !*** ./src/app/app.component.ts ***!
  \**********************************/
/*! exports provided: AppComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppComponent", function() { return AppComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/__ivy_ngcc__/fesm2015/core.js");
/* harmony import */ var ng_sidebar__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ng-sidebar */ "./node_modules/ng-sidebar/__ivy_ngcc__/lib_esmodule/index.js");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/__ivy_ngcc__/fesm2015/router.js");




class AppComponent {
    constructor() {
        this.title = 'UCNFV';
    }
}
AppComponent.ɵfac = function AppComponent_Factory(t) { return new (t || AppComponent)(); };
AppComponent.ɵcmp = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdefineComponent"]({ type: AppComponent, selectors: [["app-root"]], decls: 22, vars: 0, consts: [["rel", "stylesheet", "href", "https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css"], ["rel", "stylesheet", "href", "https://bootswatch.com/4/pulse/bootstrap.min.css"], ["sidebar", ""], [3, "click"], [1, "menu"], ["routerLink", "/Home", 3, "click"], ["routerLink", "/VNFs", 3, "click"], ["ng-sidebar-content", ""], [1, "menu-detail"]], template: function AppComponent_Template(rf, ctx) { if (rf & 1) {
        const _r1 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵgetCurrentView"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "head");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](1, "link", 0);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](2, "link", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](3, "ng-sidebar-container");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](4, "ng-sidebar", null, 2);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](6, "p");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](7, "Menu Items");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](8, "button", 3);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function AppComponent_Template_button_click_8_listener() { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵrestoreView"](_r1); const _r0 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵreference"](5); return _r0.close(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](9, "close sidebar");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](10, "ul", 4);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](11, "li");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](12, "a", 5);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function AppComponent_Template_a_click_12_listener() { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵrestoreView"](_r1); const _r0 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵreference"](5); return _r0.close(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](13, "Home");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](14, "li");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](15, "a", 6);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function AppComponent_Template_a_click_15_listener() { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵrestoreView"](_r1); const _r0 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵreference"](5); return _r0.close(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](16, "VNFs Performance");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](17, "div", 7);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](18, "button", 3);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function AppComponent_Template_button_click_18_listener() { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵrestoreView"](_r1); const _r0 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵreference"](5); return _r0.open(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](19, " Sidebar Menu ");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](20, "div", 8);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](21, "router-outlet");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
    } }, directives: [ng_sidebar__WEBPACK_IMPORTED_MODULE_1__["SidebarContainer"], ng_sidebar__WEBPACK_IMPORTED_MODULE_1__["Sidebar"], _angular_router__WEBPACK_IMPORTED_MODULE_2__["RouterLinkWithHref"], _angular_router__WEBPACK_IMPORTED_MODULE_2__["RouterOutlet"]], styles: ["ng-sidebar-container[_ngcontent-%COMP%]{\r\n    height: 100vh;\r\n}\r\n  .ng-sidebar{\r\nbackground-color: white;\r\nwidth: 300px;\r\npadding: 2em, 3em;\r\nbox-shadow: 0 0 2.5em rgba(85, 85, 85, 0.5) ;\r\n}\r\n.menu-detail[_ngcontent-%COMP%]{\r\n    \r\n    align-content: center;\r\n}\r\nhtml[_ngcontent-%COMP%] {\r\n    font-size: 14px;\r\n  }\r\n@media (min-width: 768px) {\r\n    html[_ngcontent-%COMP%] {\r\n      font-size: 16px;\r\n    }\r\n  }\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvYXBwLmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7O3VEQUV1RDtBQUN2RDtJQUNJLGFBQWE7QUFDakI7QUFDQTtBQUNBLHVCQUF1QjtBQUN2QixZQUFZO0FBQ1osaUJBQWlCO0FBQ2pCLDRDQUE0QztBQUM1QztBQUNBOztJQUVJLHFCQUFxQjtBQUN6QjtBQUNBO0lBQ0ksZUFBZTtFQUNqQjtBQUNGO0lBQ0k7TUFDRSxlQUFlO0lBQ2pCO0VBQ0YiLCJmaWxlIjoic3JjL2FwcC9hcHAuY29tcG9uZW50LmNzcyIsInNvdXJjZXNDb250ZW50IjpbIi8qICBBdXRob3IgLSBUZWphc2hyaSBKb3NoaVxyXG4gRGF0ZSAtIDEwLTIwLTIwMjBcclxuIFRoaXMgZmlsZSBjb250YWlucyBzdHlsZSBzaGVldCBmb3IgdGhlIHNpZGUgYmFyIG1lbnUgKi9cclxubmctc2lkZWJhci1jb250YWluZXJ7XHJcbiAgICBoZWlnaHQ6IDEwMHZoO1xyXG59XHJcbjo6bmctZGVlcCAubmctc2lkZWJhcntcclxuYmFja2dyb3VuZC1jb2xvcjogd2hpdGU7XHJcbndpZHRoOiAzMDBweDtcclxucGFkZGluZzogMmVtLCAzZW07XHJcbmJveC1zaGFkb3c6IDAgMCAyLjVlbSByZ2JhKDg1LCA4NSwgODUsIDAuNSkgO1xyXG59XHJcbi5tZW51LWRldGFpbHtcclxuICAgIFxyXG4gICAgYWxpZ24tY29udGVudDogY2VudGVyO1xyXG59XHJcbmh0bWwge1xyXG4gICAgZm9udC1zaXplOiAxNHB4O1xyXG4gIH1cclxuQG1lZGlhIChtaW4td2lkdGg6IDc2OHB4KSB7XHJcbiAgICBodG1sIHtcclxuICAgICAgZm9udC1zaXplOiAxNnB4O1xyXG4gICAgfVxyXG4gIH0iXX0= */"] });
/*@__PURE__*/ (function () { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵsetClassMetadata"](AppComponent, [{
        type: _angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"],
        args: [{
                selector: 'app-root',
                templateUrl: './app.component.html',
                styleUrls: ['./app.component.css']
            }]
    }], null, null); })();


/***/ }),

/***/ "./src/app/app.module.ts":
/*!*******************************!*\
  !*** ./src/app/app.module.ts ***!
  \*******************************/
/*! exports provided: AppModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppModule", function() { return AppModule; });
/* harmony import */ var _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/platform-browser */ "./node_modules/@angular/platform-browser/__ivy_ngcc__/fesm2015/platform-browser.js");
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/__ivy_ngcc__/fesm2015/core.js");
/* harmony import */ var _app_routing_module__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./app-routing.module */ "./src/app/app-routing.module.ts");
/* harmony import */ var _app_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./app.component */ "./src/app/app.component.ts");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/__ivy_ngcc__/fesm2015/http.js");
/* harmony import */ var _angular_forms__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @angular/forms */ "./node_modules/@angular/forms/__ivy_ngcc__/fesm2015/forms.js");
/* harmony import */ var _vnfs_vnfs_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./vnfs/vnfs.component */ "./src/app/vnfs/vnfs.component.ts");
/* harmony import */ var _home_home_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./home/home.component */ "./src/app/home/home.component.ts");
/* harmony import */ var ng_sidebar__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ng-sidebar */ "./node_modules/ng-sidebar/__ivy_ngcc__/lib_esmodule/index.js");
/* harmony import */ var _angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! @angular/cdk/drag-drop */ "./node_modules/@angular/cdk/__ivy_ngcc__/fesm2015/drag-drop.js");
/* harmony import */ var ngx_gauge__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(/*! ngx-gauge */ "./node_modules/ngx-gauge/__ivy_ngcc__/fesm2015/ngx-gauge.js");













class AppModule {
}
AppModule.ɵmod = _angular_core__WEBPACK_IMPORTED_MODULE_1__["ɵɵdefineNgModule"]({ type: AppModule, bootstrap: [_app_component__WEBPACK_IMPORTED_MODULE_3__["AppComponent"]] });
AppModule.ɵinj = _angular_core__WEBPACK_IMPORTED_MODULE_1__["ɵɵdefineInjector"]({ factory: function AppModule_Factory(t) { return new (t || AppModule)(); }, providers: [], imports: [[
            _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__["BrowserModule"],
            _app_routing_module__WEBPACK_IMPORTED_MODULE_2__["AppRoutingModule"],
            _angular_common_http__WEBPACK_IMPORTED_MODULE_4__["HttpClientModule"],
            _angular_forms__WEBPACK_IMPORTED_MODULE_5__["FormsModule"],
            _angular_forms__WEBPACK_IMPORTED_MODULE_5__["ReactiveFormsModule"],
            ng_sidebar__WEBPACK_IMPORTED_MODULE_8__["SidebarModule"].forRoot(),
            _angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_9__["DragDropModule"], ngx_gauge__WEBPACK_IMPORTED_MODULE_10__["NgxGaugeModule"]
        ]] });
(function () { (typeof ngJitMode === "undefined" || ngJitMode) && _angular_core__WEBPACK_IMPORTED_MODULE_1__["ɵɵsetNgModuleScope"](AppModule, { declarations: [_app_component__WEBPACK_IMPORTED_MODULE_3__["AppComponent"],
        _vnfs_vnfs_component__WEBPACK_IMPORTED_MODULE_6__["VnfsComponent"],
        _home_home_component__WEBPACK_IMPORTED_MODULE_7__["HomeComponent"]], imports: [_angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__["BrowserModule"],
        _app_routing_module__WEBPACK_IMPORTED_MODULE_2__["AppRoutingModule"],
        _angular_common_http__WEBPACK_IMPORTED_MODULE_4__["HttpClientModule"],
        _angular_forms__WEBPACK_IMPORTED_MODULE_5__["FormsModule"],
        _angular_forms__WEBPACK_IMPORTED_MODULE_5__["ReactiveFormsModule"], ng_sidebar__WEBPACK_IMPORTED_MODULE_8__["SidebarModule"], _angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_9__["DragDropModule"], ngx_gauge__WEBPACK_IMPORTED_MODULE_10__["NgxGaugeModule"]] }); })();
/*@__PURE__*/ (function () { _angular_core__WEBPACK_IMPORTED_MODULE_1__["ɵsetClassMetadata"](AppModule, [{
        type: _angular_core__WEBPACK_IMPORTED_MODULE_1__["NgModule"],
        args: [{
                declarations: [
                    _app_component__WEBPACK_IMPORTED_MODULE_3__["AppComponent"],
                    _vnfs_vnfs_component__WEBPACK_IMPORTED_MODULE_6__["VnfsComponent"],
                    _home_home_component__WEBPACK_IMPORTED_MODULE_7__["HomeComponent"]
                ],
                imports: [
                    _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__["BrowserModule"],
                    _app_routing_module__WEBPACK_IMPORTED_MODULE_2__["AppRoutingModule"],
                    _angular_common_http__WEBPACK_IMPORTED_MODULE_4__["HttpClientModule"],
                    _angular_forms__WEBPACK_IMPORTED_MODULE_5__["FormsModule"],
                    _angular_forms__WEBPACK_IMPORTED_MODULE_5__["ReactiveFormsModule"],
                    ng_sidebar__WEBPACK_IMPORTED_MODULE_8__["SidebarModule"].forRoot(),
                    _angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_9__["DragDropModule"], ngx_gauge__WEBPACK_IMPORTED_MODULE_10__["NgxGaugeModule"]
                ],
                providers: [],
                bootstrap: [_app_component__WEBPACK_IMPORTED_MODULE_3__["AppComponent"]]
            }]
    }], null, null); })();


/***/ }),

/***/ "./src/app/home/home.component.ts":
/*!****************************************!*\
  !*** ./src/app/home/home.component.ts ***!
  \****************************************/
/*! exports provided: HomeComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HomeComponent", function() { return HomeComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/__ivy_ngcc__/fesm2015/core.js");
/* harmony import */ var _vnfs_vnfs_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../vnfs/vnfs.service */ "./src/app/vnfs/vnfs.service.ts");



class HomeComponent {
    constructor(vnfService) {
        this.vnfService = vnfService;
    }
    ngOnInit() {
    }
}
HomeComponent.ɵfac = function HomeComponent_Factory(t) { return new (t || HomeComponent)(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdirectiveInject"](_vnfs_vnfs_service__WEBPACK_IMPORTED_MODULE_1__["VnfService"])); };
HomeComponent.ɵcmp = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdefineComponent"]({ type: HomeComponent, selectors: [["app-home"]], decls: 18, vars: 0, consts: [[1, "alert", "alert-dismissible", "alert-secondary"], [2, "text-align", "center"]], template: function HomeComponent_Template(rf, ctx) { if (rf & 1) {
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "div");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](1, "div", 0);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](2, "h3", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](3, "Introduction");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](4, "h2", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](5, "Network Function Virtualization (NFV) ");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](6, "h4", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](7, "It is an emerging paradigm that enables network operators to virtualize network hardware functions. Using NFV, typical physical network resources such as switches, firewalls, routers, among others can be managed or controlled as virtual network resources and therefore complementing existing cloud hardware resources ");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](8, "br");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](9, " Find more details at https://en.wikipedia.org/wiki/Network_function_virtualization");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](10, "h2", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](11, "UCNFV");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](12, "h4", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](13, " UCNFV is the User Centric approach that enables clients to selectively choose appropriate NFV services of interest. and shows Performance for selected VNF with for that provider.");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](14, "h4", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](15, "Inputs - Required VNF with a provider from list, QoS attribute weights ");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](16, "br");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](17, " Output - Performance Score of the slected VNF for that provider ");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
    } }, styles: ["\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJzcmMvYXBwL2hvbWUvaG9tZS5jb21wb25lbnQuY3NzIn0= */"] });
/*@__PURE__*/ (function () { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵsetClassMetadata"](HomeComponent, [{
        type: _angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"],
        args: [{
                selector: 'app-home',
                templateUrl: './home.component.html',
                styleUrls: ['./home.component.css']
            }]
    }], function () { return [{ type: _vnfs_vnfs_service__WEBPACK_IMPORTED_MODULE_1__["VnfService"] }]; }, null); })();


/***/ }),

/***/ "./src/app/vnfs/vnfs.component.ts":
/*!****************************************!*\
  !*** ./src/app/vnfs/vnfs.component.ts ***!
  \****************************************/
/*! exports provided: VnfsComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "VnfsComponent", function() { return VnfsComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/__ivy_ngcc__/fesm2015/core.js");
/* harmony import */ var _angular_forms__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/forms */ "./node_modules/@angular/forms/__ivy_ngcc__/fesm2015/forms.js");
/* harmony import */ var _angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/cdk/drag-drop */ "./node_modules/@angular/cdk/__ivy_ngcc__/fesm2015/drag-drop.js");
/* harmony import */ var _vnfs_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./vnfs.service */ "./src/app/vnfs/vnfs.service.ts");
/* harmony import */ var _angular_common__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @angular/common */ "./node_modules/@angular/common/__ivy_ngcc__/fesm2015/common.js");
/* harmony import */ var ngx_gauge__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ngx-gauge */ "./node_modules/ngx-gauge/__ivy_ngcc__/fesm2015/ngx-gauge.js");
/*  Author - Tejashri Joshi
 Date - 10-20-2020
This file contains methods which are called from html */









function VnfsComponent_option_11_Template(rf, ctx) { if (rf & 1) {
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "option");
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
} if (rf & 2) {
    const qos_r8 = ctx.$implicit;
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtextInterpolate"](qos_r8);
} }
function VnfsComponent_option_18_Template(rf, ctx) { if (rf & 1) {
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "option");
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
} if (rf & 2) {
    const qos_r9 = ctx.$implicit;
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtextInterpolate"](qos_r9);
} }
function VnfsComponent_div_24_Template(rf, ctx) { if (rf & 1) {
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "div");
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
} if (rf & 2) {
    const qoslist_r10 = ctx.$implicit;
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtextInterpolate2"]("", qoslist_r10.qosvalue, " ", qoslist_r10.vnfName, "");
} }
function VnfsComponent_div_32_Template(rf, ctx) { if (rf & 1) {
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "div", 24);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
} if (rf & 2) {
    const item_r11 = ctx.$implicit;
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](1);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtextInterpolate"](item_r11);
} }
function VnfsComponent_div_38_Template(rf, ctx) { if (rf & 1) {
    const _r15 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵgetCurrentView"]();
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "div");
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](1, "button", 25);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function VnfsComponent_div_38_Template_button_click_1_listener() { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵrestoreView"](_r15); const i_r13 = ctx.index; const ctx_r14 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵnextContext"](); return ctx_r14.removeItem(i_r13); });
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](2, "i", 26);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](3);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
} if (rf & 2) {
    const item_r12 = ctx.$implicit;
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](3);
    _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtextInterpolate1"]("", item_r12, " ");
} }
const _c0 = function (a0) { return [a0]; };
class VnfsComponent {
    constructor(vnfService, formBuilder) {
        this.vnfService = vnfService;
        this.formBuilder = formBuilder;
        this.VNFQoSList = [];
        this.done = [];
        this.QoSWeightCases = ['lt-Centric', 'rt-Centric', 'tp-Centric', 'av-Centric', 'rl-Centric', 'Other'];
    }
    ngOnInit() {
        // add controls to from
        this.NFVServiceform = this.formBuilder.group({ selectQoS: new _angular_forms__WEBPACK_IMPORTED_MODULE_1__["FormControl"](),
            QoSValue: new _angular_forms__WEBPACK_IMPORTED_MODULE_1__["FormControl"](),
            selectScenario: new _angular_forms__WEBPACK_IMPORTED_MODULE_1__["FormControl"]()
        });
        // get list vnf list from database
        this.vnfService.getVnfs().subscribe(data => { this.vnfList = data['vnf']; this.filteredVnf = this.vnfList; });
        // get QoS list from database
        this.vnfService.getAllQoS("Other").subscribe(data => { this.QoSList = data["name"]; this.QoSValues = data["value"]; });
        // initialize parameters for gauge
        this.gaugeType = "semi";
        this.NFVRank = '0';
        this.description = "No VNF Selected";
        this.gaugeLabel = "Performance Score";
        this.gaugeAppendText = "";
        this.min = 0;
        this.max = 1;
        this.duration = 1000;
        this.thick = 10;
        this.prevNFVValue = '0';
        this.difference = 0;
        this.thresholdConfig = {
            '0': { color: 'red' },
            '0.4': { color: 'orange' },
            '0.7': { color: 'green' }
        };
    }
    // method gets called when item dragged from list
    drop(event) {
        if (event.previousContainer !== event.container) {
            Object(_angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_2__["copyArrayItem"])(event.previousContainer.data, event.container.data, event.previousIndex, event.currentIndex);
        }
        this.submit();
    }
    // this method collects the user selected data and submit to POST and show result
    submit() {
        console.log(this.done);
        var formData = new FormData();
        for (var i in this.done) {
            formData.append('VNF' + i, this.done[i]);
        }
        ;
        if (this.VNFQoSList.length < 5) {
            alert("Please provide values for all QoS parameters");
        }
        else {
            for (let i of this.VNFQoSList) {
                formData.append(i.vnfName, i.qosvalue);
            }
        }
        this.vnfService.postVnfData(formData).subscribe(data => {
            this.NFVRank = data['name'];
            this.difference = Number(this.prevNFVValue) - Number(this.NFVRank);
            var percentage = String((Math.abs(Number(this.difference)) * 100) / Number(this.prevNFVValue));
            if (this.prevNFVValue != '0') {
                if (this.difference < 0) {
                    this.description = "The performance Score increased by " + percentage + "%";
                }
                else if (this.difference > 0) {
                    this.description = "The performance Score decreased by " + percentage + "%";
                }
                else {
                    this.description = "There is no change in performance Score";
                }
            }
            else {
                this.description = "First VNF selected";
            }
            this.prevNFVValue = this.NFVRank;
        });
    }
    // this method clears the selected VNF list
    clearList() {
        this.done = [];
        this.NFVRank = '0';
        this.description = "No VNF Selected";
        this.prevNFVValue = '0';
        this.difference = 0;
    }
    // method gets called on item removal from selected VNF list
    removeItem(index) {
        this.done.splice(index, 1);
        if (this.done.length != 0) {
            this.submit();
        }
        else {
            this.NFVRank = '0';
            this.description = "No VNF Selected";
            this.prevNFVValue = '0';
            this.difference = 0;
        }
    }
    // this method gets called when user select QoS value from drop down
    changeQoS(e) {
        this.NFVServiceform.patchValue({ selectQoS: e.target.value });
    }
    // this method gets called when user select scenario from drop down
    changeScenario(e) {
        this.NFVServiceform.patchValue({ selectScenario: e.target.value });
        //console.log("inside changescenario"+e.target.value);
        this.VNFQoSList = [];
        if (this.NFVServiceform.get("selectScenario").value != "Other") {
            this.vnfService.getAllQoS(e.target.value).subscribe(data => {
                this.QoSList = data["name"];
                this.QoSValues = data["value"];
                for (var i in this.QoSList) {
                    //console.log(this.QoSList[i],this.QoSValues[i]); 
                    this.VNFQoSList.push({ vnfName: this.QoSList[i], qosvalue: this.QoSValues[i] });
                }
            });
        }
    }
    // this method gets called on add QoS value to QoS list
    addToList() {
        var total = 0;
        this.QoSValue = this.NFVServiceform.get("QoSValue").value;
        console.log(this.NFVServiceform.get("selectQoS").value);
        this.VNFQoSList.push({ vnfName: this.NFVServiceform.get("selectQoS").value, qosvalue: this.NFVServiceform.get("QoSValue").value });
        for (let i of this.VNFQoSList) {
            total = total + Number(i.qosvalue);
            if (total > 1) {
                alert("Total Weights should not exceed 1");
            }
        }
    }
    // method to clear QoS list
    clearQoSList() {
        this.VNFQoSList = [];
        this.NFVServiceform.patchValue({ QoSValue: null });
    }
    // method to search the VNF from list
    searchVNF(e) {
        if (e.target.value != "") {
            let newList = this.vnfList.filter(function (obj) {
                //check if object value contains value you are looking for
                if (obj.toLowerCase().includes((e.target.value).toLowerCase())) {
                    //add this object to the filtered array
                    return obj;
                }
            });
            this.filteredVnf = newList;
        }
        else {
            this.filteredVnf = this.vnfList;
        }
    }
}
VnfsComponent.ɵfac = function VnfsComponent_Factory(t) { return new (t || VnfsComponent)(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdirectiveInject"](_vnfs_service__WEBPACK_IMPORTED_MODULE_3__["VnfService"]), _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdirectiveInject"](_angular_forms__WEBPACK_IMPORTED_MODULE_1__["FormBuilder"])); };
VnfsComponent.ɵcmp = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdefineComponent"]({ type: VnfsComponent, selectors: [["app-vnfs"]], decls: 46, vars: 25, consts: [[3, "formGroup", "ngSubmit"], [1, "alert", "alert-dismissible", "alert-secondary"], [2, "text-align", "center"], [1, "form-group"], ["for", "Scenarios"], ["formControlName", "selectScenario", 1, "custom-select", 3, "change"], ["selectScenario", ""], ["value", "Other", "selected", ""], [4, "ngFor", "ngForOf"], ["for", "QoSList"], ["formControlName", "selectQoS", 1, "custom-select", 3, "change"], ["value", "", "selected", ""], ["type", "text", "placeholder", "Eneter Value", "formControlName", "QoSValue", 1, "form-control"], ["type", "button", 1, "btn", "btn-outline-primary", 3, "disabled", "click"], ["type", "button", 1, "btn", "btn-outline-primary", 3, "click"], [1, "example-container"], ["type", "text", "placeholder", "Search VNFs Here", 1, "form-control", 3, "input"], ["cdkDropList", "", 1, "example-list", 3, "cdkDropListData", "cdkDropListConnectedTo"], ["todoList", "cdkDropList"], ["cdkDrag", "", 4, "ngFor", "ngForOf"], ["cdkDropList", "", 1, "example-list", 3, "cdkDropListData", "cdkDropListConnectedTo", "cdkDropListDropped"], ["doneList", "cdkDropList"], [1, "result"], [3, "type", "value", "label", "prepend", "min", "max", "thick", "thresholds", "duration"], ["cdkDrag", ""], [1, "btn", "btn-outline-info", 3, "click"], [1, "fa", "fa-trash"]], template: function VnfsComponent_Template(rf, ctx) { if (rf & 1) {
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](0, "form", 0);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("ngSubmit", function VnfsComponent_Template_form_ngSubmit_0_listener() { return ctx.submit(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](1, "div", 1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](2, "h3", 2);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](3, "Check Performance of Virtual Network Functions");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](4, "div", 3);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](5, "label", 4);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](6, "Scenarios:");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](7, "select", 5, 6);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("change", function VnfsComponent_Template_select_change_7_listener($event) { return ctx.changeScenario($event); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](9, "option", 7);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](10, "Select Scenario");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtemplate"](11, VnfsComponent_option_11_Template, 2, 1, "option", 8);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](12, "div", 3);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](13, "label", 9);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](14, "QoSList:");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](15, "select", 10);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("change", function VnfsComponent_Template_select_change_15_listener($event) { return ctx.changeQoS($event); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](16, "option", 11);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](17, "Select QoS");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtemplate"](18, VnfsComponent_option_18_Template, 2, 1, "option", 8);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](19, "input", 12);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](20, "button", 13);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function VnfsComponent_Template_button_click_20_listener() { return ctx.addToList(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](21, "Add to List");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](22, "button", 14);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function VnfsComponent_Template_button_click_22_listener() { return ctx.clearQoSList(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](23, "Clear List");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtemplate"](24, VnfsComponent_div_24_Template, 2, 2, "div", 8);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](25, "hr");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](26, "div", 15);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](27, "h2");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](28, "List Of VNFs");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](29, "input", 16);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("input", function VnfsComponent_Template_input_input_29_listener($event) { return ctx.searchVNF($event); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](30, "div", 17, 18);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtemplate"](32, VnfsComponent_div_32_Template, 2, 1, "div", 19);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](33, "div", 15);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](34, "h2");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](35, "Drag VNFs here");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](36, "div", 20, 21);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("cdkDropListDropped", function VnfsComponent_Template_div_cdkDropListDropped_36_listener($event) { return ctx.drop($event); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtemplate"](38, VnfsComponent_div_38_Template, 4, 1, "div", 8);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](39, "button", 14);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵlistener"]("click", function VnfsComponent_Template_button_click_39_listener() { return ctx.clearList(); });
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](40, "Clear target List");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](41, "div", 22);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](42, "div");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementStart"](43, "label");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtext"](44);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelement"](45, "ngx-gauge", 23);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵelementEnd"]();
    } if (rf & 2) {
        const _r0 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵreference"](8);
        const _r4 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵreference"](31);
        const _r6 = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵreference"](37);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("formGroup", ctx.NFVServiceform);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](11);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("ngForOf", ctx.QoSWeightCases);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](7);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("ngForOf", ctx.QoSList);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](2);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("disabled", _r0.value != "Other");
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](4);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("ngForOf", ctx.VNFQoSList);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](6);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("cdkDropListData", ctx.filteredVnf)("cdkDropListConnectedTo", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵpureFunction1"](21, _c0, _r6));
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](2);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("ngForOf", ctx.filteredVnf);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](4);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("cdkDropListData", ctx.done)("cdkDropListConnectedTo", _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵpureFunction1"](23, _c0, _r4));
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](2);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("ngForOf", ctx.done);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](6);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵtextInterpolate"](ctx.description);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵadvance"](1);
        _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵproperty"]("type", ctx.gaugeType)("value", ctx.NFVRank)("label", ctx.gaugeLabel)("prepend", ctx.gaugeAppendText)("min", ctx.min)("max", ctx.max)("thick", ctx.thick)("thresholds", ctx.thresholdConfig)("duration", ctx.duration);
    } }, directives: [_angular_forms__WEBPACK_IMPORTED_MODULE_1__["ɵangular_packages_forms_forms_y"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["NgControlStatusGroup"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["FormGroupDirective"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["SelectControlValueAccessor"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["NgControlStatus"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["FormControlName"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["NgSelectOption"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["ɵangular_packages_forms_forms_x"], _angular_common__WEBPACK_IMPORTED_MODULE_4__["NgForOf"], _angular_forms__WEBPACK_IMPORTED_MODULE_1__["DefaultValueAccessor"], _angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_2__["CdkDropList"], ngx_gauge__WEBPACK_IMPORTED_MODULE_5__["ɵa"], _angular_cdk_drag_drop__WEBPACK_IMPORTED_MODULE_2__["CdkDrag"]], styles: [".example-container[_ngcontent-%COMP%] {\r\n    float: left;\r\n    width: 300px;\r\n    height: 300px;\r\n    \r\n    max-width: 100%;\r\n    margin-top: 400;\r\n    margin: 0 100px 100px 80px;\r\n\r\n    border: solid 3px black;  \r\n    overflow: scroll; \r\n}\r\n.example-list[_ngcontent-%COMP%] {\r\n    border: solid 1px #ccc;\r\n    min-height: 60px;\r\n    background: white;\r\n    border-radius: 4px;\r\n\r\n    height:700px;   \r\n    font-size: 14px;  \r\n    border-bottom: solid 1px #ccc; \r\n    padding: 10px 10px;\r\n    align-items: center;\r\n\r\n}\r\n.result[_ngcontent-%COMP%]{\r\n    float: left;\r\n    width: 250px;\r\n    height: 300px;\r\n\r\n    max-width: 100%;\r\n    \r\n    margin: 0 25px 25px 80px;\r\n\r\n}\r\n.form-group[_ngcontent-%COMP%]{\r\n    width: 30%;\r\n    margin: auto;\r\n\r\n}\r\n.cdk-drag-preview[_ngcontent-%COMP%] {\r\n    box-sizing: border-box;\r\n    border-radius: 4px;\r\n    box-shadow: 0 5px 5px -3px rgba(0, 0, 0, 0.2),\r\n                0 8px 10px 1px rgba(0, 0, 0, 0.14),\r\n                0 3px 14px 2px rgba(0, 0, 0, 0.12);\r\n}\r\n.cdk-drag-placeholder[_ngcontent-%COMP%] {\r\n    opacity: 0;\r\n}\r\n.cdk-drag-animating[_ngcontent-%COMP%] {\r\n    transition: transform 250ms cubic-bezier(0, 0, 0.2, 1);\r\n}\r\n.example-box[_ngcontent-%COMP%]:last-child {\r\n    border: none;\r\n}\r\n.example-list.cdk-drop-list-dragging[_ngcontent-%COMP%]   .example-box[_ngcontent-%COMP%]:not(.cdk-drag-placeholder) {\r\n    transition: transform 250ms cubic-bezier(0, 0, 0.2, 1);\r\n}\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvdm5mcy92bmZzLmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7OytEQUUrRDtBQUMvRDtJQUNJLFdBQVc7SUFDWCxZQUFZO0lBQ1osYUFBYTs7SUFFYixlQUFlO0lBQ2YsZUFBZTtJQUNmLDBCQUEwQjs7SUFFMUIsdUJBQXVCO0lBQ3ZCLGdCQUFnQjtBQUNwQjtBQUNBO0lBQ0ksc0JBQXNCO0lBQ3RCLGdCQUFnQjtJQUNoQixpQkFBaUI7SUFDakIsa0JBQWtCOztJQUVsQixZQUFZO0lBQ1osZUFBZTtJQUNmLDZCQUE2QjtJQUM3QixrQkFBa0I7SUFDbEIsbUJBQW1COztBQUV2QjtBQUVBO0lBQ0ksV0FBVztJQUNYLFlBQVk7SUFDWixhQUFhOztJQUViLGVBQWU7O0lBRWYsd0JBQXdCOztBQUU1QjtBQUNBO0lBQ0ksVUFBVTtJQUNWLFlBQVk7O0FBRWhCO0FBRUE7SUFDSSxzQkFBc0I7SUFDdEIsa0JBQWtCO0lBQ2xCOztrREFFOEM7QUFDbEQ7QUFFQTtJQUNJLFVBQVU7QUFDZDtBQUVBO0lBQ0ksc0RBQXNEO0FBQzFEO0FBRUE7SUFDSSxZQUFZO0FBQ2hCO0FBRUE7SUFDSSxzREFBc0Q7QUFDMUQiLCJmaWxlIjoic3JjL2FwcC92bmZzL3ZuZnMuY29tcG9uZW50LmNzcyIsInNvdXJjZXNDb250ZW50IjpbIi8qICBBdXRob3IgLSBUZWphc2hyaSBKb3NoaVxyXG4gRGF0ZSAtIDEwLTIwLTIwMjBcclxuVGhpcyBmaWxlIGNvbnRhaW5zIHN0eWxlIGZvciBlbGVtZW50cyBvbiBWTkYgcGVyZm9ybWFuY2UgcGFnZSAqL1xyXG4uZXhhbXBsZS1jb250YWluZXIge1xyXG4gICAgZmxvYXQ6IGxlZnQ7XHJcbiAgICB3aWR0aDogMzAwcHg7XHJcbiAgICBoZWlnaHQ6IDMwMHB4O1xyXG4gICAgXHJcbiAgICBtYXgtd2lkdGg6IDEwMCU7XHJcbiAgICBtYXJnaW4tdG9wOiA0MDA7XHJcbiAgICBtYXJnaW46IDAgMTAwcHggMTAwcHggODBweDtcclxuXHJcbiAgICBib3JkZXI6IHNvbGlkIDNweCBibGFjazsgIFxyXG4gICAgb3ZlcmZsb3c6IHNjcm9sbDsgXHJcbn1cclxuLmV4YW1wbGUtbGlzdCB7XHJcbiAgICBib3JkZXI6IHNvbGlkIDFweCAjY2NjO1xyXG4gICAgbWluLWhlaWdodDogNjBweDtcclxuICAgIGJhY2tncm91bmQ6IHdoaXRlO1xyXG4gICAgYm9yZGVyLXJhZGl1czogNHB4O1xyXG5cclxuICAgIGhlaWdodDo3MDBweDsgICBcclxuICAgIGZvbnQtc2l6ZTogMTRweDsgIFxyXG4gICAgYm9yZGVyLWJvdHRvbTogc29saWQgMXB4ICNjY2M7IFxyXG4gICAgcGFkZGluZzogMTBweCAxMHB4O1xyXG4gICAgYWxpZ24taXRlbXM6IGNlbnRlcjtcclxuXHJcbn1cclxuXHJcbi5yZXN1bHR7XHJcbiAgICBmbG9hdDogbGVmdDtcclxuICAgIHdpZHRoOiAyNTBweDtcclxuICAgIGhlaWdodDogMzAwcHg7XHJcblxyXG4gICAgbWF4LXdpZHRoOiAxMDAlO1xyXG4gICAgXHJcbiAgICBtYXJnaW46IDAgMjVweCAyNXB4IDgwcHg7XHJcblxyXG59XHJcbi5mb3JtLWdyb3Vwe1xyXG4gICAgd2lkdGg6IDMwJTtcclxuICAgIG1hcmdpbjogYXV0bztcclxuXHJcbn1cclxuXHJcbi5jZGstZHJhZy1wcmV2aWV3IHtcclxuICAgIGJveC1zaXppbmc6IGJvcmRlci1ib3g7XHJcbiAgICBib3JkZXItcmFkaXVzOiA0cHg7XHJcbiAgICBib3gtc2hhZG93OiAwIDVweCA1cHggLTNweCByZ2JhKDAsIDAsIDAsIDAuMiksXHJcbiAgICAgICAgICAgICAgICAwIDhweCAxMHB4IDFweCByZ2JhKDAsIDAsIDAsIDAuMTQpLFxyXG4gICAgICAgICAgICAgICAgMCAzcHggMTRweCAycHggcmdiYSgwLCAwLCAwLCAwLjEyKTtcclxufVxyXG5cclxuLmNkay1kcmFnLXBsYWNlaG9sZGVyIHtcclxuICAgIG9wYWNpdHk6IDA7XHJcbn1cclxuXHJcbi5jZGstZHJhZy1hbmltYXRpbmcge1xyXG4gICAgdHJhbnNpdGlvbjogdHJhbnNmb3JtIDI1MG1zIGN1YmljLWJlemllcigwLCAwLCAwLjIsIDEpO1xyXG59XHJcblxyXG4uZXhhbXBsZS1ib3g6bGFzdC1jaGlsZCB7XHJcbiAgICBib3JkZXI6IG5vbmU7XHJcbn1cclxuXHJcbi5leGFtcGxlLWxpc3QuY2RrLWRyb3AtbGlzdC1kcmFnZ2luZyAuZXhhbXBsZS1ib3g6bm90KC5jZGstZHJhZy1wbGFjZWhvbGRlcikge1xyXG4gICAgdHJhbnNpdGlvbjogdHJhbnNmb3JtIDI1MG1zIGN1YmljLWJlemllcigwLCAwLCAwLjIsIDEpO1xyXG59Il19 */"] });
/*@__PURE__*/ (function () { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵsetClassMetadata"](VnfsComponent, [{
        type: _angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"],
        args: [{
                selector: 'app-vnfs',
                templateUrl: './vnfs.component.html',
                styleUrls: ['./vnfs.component.css']
            }]
    }], function () { return [{ type: _vnfs_service__WEBPACK_IMPORTED_MODULE_3__["VnfService"] }, { type: _angular_forms__WEBPACK_IMPORTED_MODULE_1__["FormBuilder"] }]; }, null); })();


/***/ }),

/***/ "./src/app/vnfs/vnfs.service.ts":
/*!**************************************!*\
  !*** ./src/app/vnfs/vnfs.service.ts ***!
  \**************************************/
/*! exports provided: VnfService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "VnfService", function() { return VnfService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/__ivy_ngcc__/fesm2015/core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/__ivy_ngcc__/fesm2015/http.js");
// Author - Tejashri Joshi
// Date - 10-15-2020
// This file contains the call to the REST APIs developed in python 



class VnfService {
    constructor(httpClient) {
        this.httpClient = httpClient;
    }
    getVnfs() {
        return this.httpClient.get('http://localhost:5000/VNF');
    }
    getAllQoS(scenario) {
        return this.httpClient.get('http://localhost:5000/QoS/' + scenario);
    }
    postVnfData(vnfQoS) {
        //const httpHeaders = new HttpHeaders({'Content-Type': 'application/json'});
        return this.httpClient.post('http://localhost:5000/perfScore', vnfQoS); //,{headers:httpHeaders});
    }
}
VnfService.ɵfac = function VnfService_Factory(t) { return new (t || VnfService)(_angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵinject"](_angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpClient"])); };
VnfService.ɵprov = _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵɵdefineInjectable"]({ token: VnfService, factory: VnfService.ɵfac, providedIn: 'root' });
/*@__PURE__*/ (function () { _angular_core__WEBPACK_IMPORTED_MODULE_0__["ɵsetClassMetadata"](VnfService, [{
        type: _angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"],
        args: [{
                providedIn: 'root'
            }]
    }], function () { return [{ type: _angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpClient"] }]; }, null); })();


/***/ }),

/***/ "./src/environments/environment.ts":
/*!*****************************************!*\
  !*** ./src/environments/environment.ts ***!
  \*****************************************/
/*! exports provided: environment */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "environment", function() { return environment; });
// This file can be replaced during build by using the `fileReplacements` array.
// `ng build --prod` replaces `environment.ts` with `environment.prod.ts`.
// The list of file replacements can be found in `angular.json`.
const environment = {
    production: false
};
/*
 * For easier debugging in development mode, you can import the following file
 * to ignore zone related error stack frames such as `zone.run`, `zoneDelegate.invokeTask`.
 *
 * This import should be commented out in production mode because it will have a negative impact
 * on performance if an error is thrown.
 */
// import 'zone.js/dist/zone-error';  // Included with Angular CLI.


/***/ }),

/***/ "./src/main.ts":
/*!*********************!*\
  !*** ./src/main.ts ***!
  \*********************/
/*! no exports provided */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/__ivy_ngcc__/fesm2015/core.js");
/* harmony import */ var _environments_environment__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./environments/environment */ "./src/environments/environment.ts");
/* harmony import */ var _app_app_module__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./app/app.module */ "./src/app/app.module.ts");
/* harmony import */ var _angular_platform_browser__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @angular/platform-browser */ "./node_modules/@angular/platform-browser/__ivy_ngcc__/fesm2015/platform-browser.js");




if (_environments_environment__WEBPACK_IMPORTED_MODULE_1__["environment"].production) {
    Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["enableProdMode"])();
}
_angular_platform_browser__WEBPACK_IMPORTED_MODULE_3__["platformBrowser"]().bootstrapModule(_app_app_module__WEBPACK_IMPORTED_MODULE_2__["AppModule"])
    .catch(err => console.error(err));


/***/ }),

/***/ 0:
/*!***************************!*\
  !*** multi ./src/main.ts ***!
  \***************************/
/*! no static exports found */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(/*! C:\Users\Teju\Documents\Teju\TEJU MS\Capstone project\code\UCNFV\Angular\src\main.ts */"./src/main.ts");


/***/ })

},[[0,"runtime","vendor"]]]);
//# sourceMappingURL=main.js.map