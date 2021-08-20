import { Role } from "./role";

export class User {
     userId: number;
     firstName: string;
     lastName: string;
     userName: string;
     password: string;
     emailAddress:string; 
     age:number;
     gender:string;
     role: Role;
}
