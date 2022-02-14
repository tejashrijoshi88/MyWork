//File contains functions to validate the fields on registration page                                     
//Author - Tejashri Joshi                                                                 
//Date   - 12/12/2020     
import { FormGroup, AbstractControl } from "@angular/forms";

// To validate password and confirm password

export function ComparePassword(
  controlName: string,
  matchingControlName: string
) {
  return (formGroup: FormGroup) => {
    const control = formGroup.controls[controlName];
    const matchingControl = formGroup.controls[matchingControlName];

    if (matchingControl.errors && !matchingControl.errors.mustMatch) {
      return;
    }

    if (control.value !== matchingControl.value) {
      matchingControl.setErrors({ mustMatch: true });
    } else {
      matchingControl.setErrors(null);
    }
  };
}
export function UserNameCheck(controlName: AbstractControl) {
  let userName = controlName.value;
  if (userName != null) {
    var regexp = new RegExp('^[a-zA-Z._]+$');
    //console.log(userName);
    console.log(regexp.test(userName));
    if (regexp.test(userName) !== true) {
      return { userNameValidity: true }
    }
    return null;
  }
}
// to validate password
export function PasswordCheck(controlName: AbstractControl) {
  let password = controlName.value;
  // check password with regex- having 1 uppercase, lowercase,number and special char
  if (password != null) {
    var regexp1 = new RegExp('^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[$@$!%*?&])[A-Za-z\\d$@$!%*?&]{8,}');
    //console.log(password);
    //console.log(regexp1.test(password));
    if (regexp1.test(password) !== true) {
      return { passwordValidity: true }
    }
    return null;
  }
}
// validate emailId
export function EmailIdCheck(controlName: AbstractControl) {
  let email = controlName.value;
  // regex to validate email
  if (email != null) {
    var regexp1 = new RegExp('^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$');
    //console.log(password);
    //console.log(regexp1.test(password));
    if (regexp1.test(email) !== true) {
      return { emailValidity: true }
    }
    return null;
  }
}
