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
void car_err_fun(double *nom_x, double *delta_x, double *out_7601140416182293853);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8515902340586860735);
void car_H_mod_fun(double *state, double *out_2217032637436483966);
void car_f_fun(double *state, double dt, double *out_3186535248829676437);
void car_F_fun(double *state, double dt, double *out_4268212592728321604);
void car_h_25(double *state, double *unused, double *out_5623648446326736274);
void car_H_25(double *state, double *unused, double *out_4979319111069112730);
void car_h_24(double *state, double *unused, double *out_5657381027351914870);
void car_H_24(double *state, double *unused, double *out_7156533534676262703);
void car_h_30(double *state, double *unused, double *out_1986198918072713924);
void car_H_30(double *state, double *unused, double *out_7497652069576361357);
void car_h_26(double *state, double *unused, double *out_7664235691370840552);
void car_H_26(double *state, double *unused, double *out_1237815792195056506);
void car_h_27(double *state, double *unused, double *out_8660434497771068959);
void car_H_27(double *state, double *unused, double *out_5322888757775936446);
void car_h_29(double *state, double *unused, double *out_8385240435486563070);
void car_H_29(double *state, double *unused, double *out_8007883413890753541);
void car_h_28(double *state, double *unused, double *out_8842799723036820222);
void car_H_28(double *state, double *unused, double *out_2925484396821222967);
void car_h_31(double *state, double *unused, double *out_5898842508611242163);
void car_H_31(double *state, double *unused, double *out_611607689961705030);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}