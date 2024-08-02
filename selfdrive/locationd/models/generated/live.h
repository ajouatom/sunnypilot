#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_4723732251547718860);
void live_err_fun(double *nom_x, double *delta_x, double *out_8039421302295105776);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_5258012845381697229);
void live_H_mod_fun(double *state, double *out_4602111055287638084);
void live_f_fun(double *state, double dt, double *out_2494991483937947279);
void live_F_fun(double *state, double dt, double *out_5242126298311218128);
void live_h_4(double *state, double *unused, double *out_7557171517810886780);
void live_H_4(double *state, double *unused, double *out_666163721163740906);
void live_h_9(double *state, double *unused, double *out_4575917590972209973);
void live_H_9(double *state, double *unused, double *out_6621055214100706564);
void live_h_10(double *state, double *unused, double *out_2542662905733650449);
void live_H_10(double *state, double *unused, double *out_191145321231249777);
void live_h_12(double *state, double *unused, double *out_5988229625246386217);
void live_H_12(double *state, double *unused, double *out_7047422098206473902);
void live_h_35(double *state, double *unused, double *out_1884394027017516911);
void live_H_35(double *state, double *unused, double *out_2700498336208866470);
void live_h_32(double *state, double *unused, double *out_4367162044804246157);
void live_H_32(double *state, double *unused, double *out_1518200901463042600);
void live_h_13(double *state, double *unused, double *out_8085451560721964132);
void live_H_13(double *state, double *unused, double *out_8479815537807308948);
void live_h_14(double *state, double *unused, double *out_4575917590972209973);
void live_H_14(double *state, double *unused, double *out_6621055214100706564);
void live_h_33(double *state, double *unused, double *out_5161320250989203859);
void live_H_33(double *state, double *unused, double *out_5851055340847724074);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}