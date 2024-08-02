#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7163063568989676842);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3754260694415491349);
void car_H_mod_fun(double *state, double *out_8878594360494595028);
void car_f_fun(double *state, double dt, double *out_32589037743347182);
void car_F_fun(double *state, double dt, double *out_2355328765180068083);
void car_h_25(double *state, double *unused, double *out_1013193562225998629);
void car_H_25(double *state, double *unused, double *out_993794256298495203);
void car_h_24(double *state, double *unused, double *out_4596273345226045289);
void car_H_24(double *state, double *unused, double *out_4551719855100818339);
void car_h_30(double *state, double *unused, double *out_7601021488702293792);
void car_H_30(double *state, double *unused, double *out_3512127214805743830);
void car_h_26(double *state, double *unused, double *out_8544531341603956227);
void car_H_26(double *state, double *unused, double *out_2747709062575561021);
void car_h_27(double *state, double *unused, double *out_1616509446902476146);
void car_H_27(double *state, double *unused, double *out_5735721285989687047);
void car_h_29(double *state, double *unused, double *out_4564235437257961107);
void car_H_29(double *state, double *unused, double *out_4022358559120136014);
void car_h_28(double *state, double *unused, double *out_987895873906221505);
void car_H_28(double *state, double *unused, double *out_1060040457949394560);
void car_h_31(double *state, double *unused, double *out_3227977152407240354);
void car_H_31(double *state, double *unused, double *out_1024440218175455631);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}