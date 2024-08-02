#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7601140416182293853) {
   out_7601140416182293853[0] = delta_x[0] + nom_x[0];
   out_7601140416182293853[1] = delta_x[1] + nom_x[1];
   out_7601140416182293853[2] = delta_x[2] + nom_x[2];
   out_7601140416182293853[3] = delta_x[3] + nom_x[3];
   out_7601140416182293853[4] = delta_x[4] + nom_x[4];
   out_7601140416182293853[5] = delta_x[5] + nom_x[5];
   out_7601140416182293853[6] = delta_x[6] + nom_x[6];
   out_7601140416182293853[7] = delta_x[7] + nom_x[7];
   out_7601140416182293853[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8515902340586860735) {
   out_8515902340586860735[0] = -nom_x[0] + true_x[0];
   out_8515902340586860735[1] = -nom_x[1] + true_x[1];
   out_8515902340586860735[2] = -nom_x[2] + true_x[2];
   out_8515902340586860735[3] = -nom_x[3] + true_x[3];
   out_8515902340586860735[4] = -nom_x[4] + true_x[4];
   out_8515902340586860735[5] = -nom_x[5] + true_x[5];
   out_8515902340586860735[6] = -nom_x[6] + true_x[6];
   out_8515902340586860735[7] = -nom_x[7] + true_x[7];
   out_8515902340586860735[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2217032637436483966) {
   out_2217032637436483966[0] = 1.0;
   out_2217032637436483966[1] = 0;
   out_2217032637436483966[2] = 0;
   out_2217032637436483966[3] = 0;
   out_2217032637436483966[4] = 0;
   out_2217032637436483966[5] = 0;
   out_2217032637436483966[6] = 0;
   out_2217032637436483966[7] = 0;
   out_2217032637436483966[8] = 0;
   out_2217032637436483966[9] = 0;
   out_2217032637436483966[10] = 1.0;
   out_2217032637436483966[11] = 0;
   out_2217032637436483966[12] = 0;
   out_2217032637436483966[13] = 0;
   out_2217032637436483966[14] = 0;
   out_2217032637436483966[15] = 0;
   out_2217032637436483966[16] = 0;
   out_2217032637436483966[17] = 0;
   out_2217032637436483966[18] = 0;
   out_2217032637436483966[19] = 0;
   out_2217032637436483966[20] = 1.0;
   out_2217032637436483966[21] = 0;
   out_2217032637436483966[22] = 0;
   out_2217032637436483966[23] = 0;
   out_2217032637436483966[24] = 0;
   out_2217032637436483966[25] = 0;
   out_2217032637436483966[26] = 0;
   out_2217032637436483966[27] = 0;
   out_2217032637436483966[28] = 0;
   out_2217032637436483966[29] = 0;
   out_2217032637436483966[30] = 1.0;
   out_2217032637436483966[31] = 0;
   out_2217032637436483966[32] = 0;
   out_2217032637436483966[33] = 0;
   out_2217032637436483966[34] = 0;
   out_2217032637436483966[35] = 0;
   out_2217032637436483966[36] = 0;
   out_2217032637436483966[37] = 0;
   out_2217032637436483966[38] = 0;
   out_2217032637436483966[39] = 0;
   out_2217032637436483966[40] = 1.0;
   out_2217032637436483966[41] = 0;
   out_2217032637436483966[42] = 0;
   out_2217032637436483966[43] = 0;
   out_2217032637436483966[44] = 0;
   out_2217032637436483966[45] = 0;
   out_2217032637436483966[46] = 0;
   out_2217032637436483966[47] = 0;
   out_2217032637436483966[48] = 0;
   out_2217032637436483966[49] = 0;
   out_2217032637436483966[50] = 1.0;
   out_2217032637436483966[51] = 0;
   out_2217032637436483966[52] = 0;
   out_2217032637436483966[53] = 0;
   out_2217032637436483966[54] = 0;
   out_2217032637436483966[55] = 0;
   out_2217032637436483966[56] = 0;
   out_2217032637436483966[57] = 0;
   out_2217032637436483966[58] = 0;
   out_2217032637436483966[59] = 0;
   out_2217032637436483966[60] = 1.0;
   out_2217032637436483966[61] = 0;
   out_2217032637436483966[62] = 0;
   out_2217032637436483966[63] = 0;
   out_2217032637436483966[64] = 0;
   out_2217032637436483966[65] = 0;
   out_2217032637436483966[66] = 0;
   out_2217032637436483966[67] = 0;
   out_2217032637436483966[68] = 0;
   out_2217032637436483966[69] = 0;
   out_2217032637436483966[70] = 1.0;
   out_2217032637436483966[71] = 0;
   out_2217032637436483966[72] = 0;
   out_2217032637436483966[73] = 0;
   out_2217032637436483966[74] = 0;
   out_2217032637436483966[75] = 0;
   out_2217032637436483966[76] = 0;
   out_2217032637436483966[77] = 0;
   out_2217032637436483966[78] = 0;
   out_2217032637436483966[79] = 0;
   out_2217032637436483966[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3186535248829676437) {
   out_3186535248829676437[0] = state[0];
   out_3186535248829676437[1] = state[1];
   out_3186535248829676437[2] = state[2];
   out_3186535248829676437[3] = state[3];
   out_3186535248829676437[4] = state[4];
   out_3186535248829676437[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3186535248829676437[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3186535248829676437[7] = state[7];
   out_3186535248829676437[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4268212592728321604) {
   out_4268212592728321604[0] = 1;
   out_4268212592728321604[1] = 0;
   out_4268212592728321604[2] = 0;
   out_4268212592728321604[3] = 0;
   out_4268212592728321604[4] = 0;
   out_4268212592728321604[5] = 0;
   out_4268212592728321604[6] = 0;
   out_4268212592728321604[7] = 0;
   out_4268212592728321604[8] = 0;
   out_4268212592728321604[9] = 0;
   out_4268212592728321604[10] = 1;
   out_4268212592728321604[11] = 0;
   out_4268212592728321604[12] = 0;
   out_4268212592728321604[13] = 0;
   out_4268212592728321604[14] = 0;
   out_4268212592728321604[15] = 0;
   out_4268212592728321604[16] = 0;
   out_4268212592728321604[17] = 0;
   out_4268212592728321604[18] = 0;
   out_4268212592728321604[19] = 0;
   out_4268212592728321604[20] = 1;
   out_4268212592728321604[21] = 0;
   out_4268212592728321604[22] = 0;
   out_4268212592728321604[23] = 0;
   out_4268212592728321604[24] = 0;
   out_4268212592728321604[25] = 0;
   out_4268212592728321604[26] = 0;
   out_4268212592728321604[27] = 0;
   out_4268212592728321604[28] = 0;
   out_4268212592728321604[29] = 0;
   out_4268212592728321604[30] = 1;
   out_4268212592728321604[31] = 0;
   out_4268212592728321604[32] = 0;
   out_4268212592728321604[33] = 0;
   out_4268212592728321604[34] = 0;
   out_4268212592728321604[35] = 0;
   out_4268212592728321604[36] = 0;
   out_4268212592728321604[37] = 0;
   out_4268212592728321604[38] = 0;
   out_4268212592728321604[39] = 0;
   out_4268212592728321604[40] = 1;
   out_4268212592728321604[41] = 0;
   out_4268212592728321604[42] = 0;
   out_4268212592728321604[43] = 0;
   out_4268212592728321604[44] = 0;
   out_4268212592728321604[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4268212592728321604[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4268212592728321604[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4268212592728321604[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4268212592728321604[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4268212592728321604[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4268212592728321604[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4268212592728321604[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4268212592728321604[53] = -9.8000000000000007*dt;
   out_4268212592728321604[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4268212592728321604[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4268212592728321604[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4268212592728321604[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4268212592728321604[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4268212592728321604[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4268212592728321604[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4268212592728321604[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4268212592728321604[62] = 0;
   out_4268212592728321604[63] = 0;
   out_4268212592728321604[64] = 0;
   out_4268212592728321604[65] = 0;
   out_4268212592728321604[66] = 0;
   out_4268212592728321604[67] = 0;
   out_4268212592728321604[68] = 0;
   out_4268212592728321604[69] = 0;
   out_4268212592728321604[70] = 1;
   out_4268212592728321604[71] = 0;
   out_4268212592728321604[72] = 0;
   out_4268212592728321604[73] = 0;
   out_4268212592728321604[74] = 0;
   out_4268212592728321604[75] = 0;
   out_4268212592728321604[76] = 0;
   out_4268212592728321604[77] = 0;
   out_4268212592728321604[78] = 0;
   out_4268212592728321604[79] = 0;
   out_4268212592728321604[80] = 1;
}
void h_25(double *state, double *unused, double *out_5623648446326736274) {
   out_5623648446326736274[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4979319111069112730) {
   out_4979319111069112730[0] = 0;
   out_4979319111069112730[1] = 0;
   out_4979319111069112730[2] = 0;
   out_4979319111069112730[3] = 0;
   out_4979319111069112730[4] = 0;
   out_4979319111069112730[5] = 0;
   out_4979319111069112730[6] = 1;
   out_4979319111069112730[7] = 0;
   out_4979319111069112730[8] = 0;
}
void h_24(double *state, double *unused, double *out_5657381027351914870) {
   out_5657381027351914870[0] = state[4];
   out_5657381027351914870[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7156533534676262703) {
   out_7156533534676262703[0] = 0;
   out_7156533534676262703[1] = 0;
   out_7156533534676262703[2] = 0;
   out_7156533534676262703[3] = 0;
   out_7156533534676262703[4] = 1;
   out_7156533534676262703[5] = 0;
   out_7156533534676262703[6] = 0;
   out_7156533534676262703[7] = 0;
   out_7156533534676262703[8] = 0;
   out_7156533534676262703[9] = 0;
   out_7156533534676262703[10] = 0;
   out_7156533534676262703[11] = 0;
   out_7156533534676262703[12] = 0;
   out_7156533534676262703[13] = 0;
   out_7156533534676262703[14] = 1;
   out_7156533534676262703[15] = 0;
   out_7156533534676262703[16] = 0;
   out_7156533534676262703[17] = 0;
}
void h_30(double *state, double *unused, double *out_1986198918072713924) {
   out_1986198918072713924[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7497652069576361357) {
   out_7497652069576361357[0] = 0;
   out_7497652069576361357[1] = 0;
   out_7497652069576361357[2] = 0;
   out_7497652069576361357[3] = 0;
   out_7497652069576361357[4] = 1;
   out_7497652069576361357[5] = 0;
   out_7497652069576361357[6] = 0;
   out_7497652069576361357[7] = 0;
   out_7497652069576361357[8] = 0;
}
void h_26(double *state, double *unused, double *out_7664235691370840552) {
   out_7664235691370840552[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1237815792195056506) {
   out_1237815792195056506[0] = 0;
   out_1237815792195056506[1] = 0;
   out_1237815792195056506[2] = 0;
   out_1237815792195056506[3] = 0;
   out_1237815792195056506[4] = 0;
   out_1237815792195056506[5] = 0;
   out_1237815792195056506[6] = 0;
   out_1237815792195056506[7] = 1;
   out_1237815792195056506[8] = 0;
}
void h_27(double *state, double *unused, double *out_8660434497771068959) {
   out_8660434497771068959[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5322888757775936446) {
   out_5322888757775936446[0] = 0;
   out_5322888757775936446[1] = 0;
   out_5322888757775936446[2] = 0;
   out_5322888757775936446[3] = 1;
   out_5322888757775936446[4] = 0;
   out_5322888757775936446[5] = 0;
   out_5322888757775936446[6] = 0;
   out_5322888757775936446[7] = 0;
   out_5322888757775936446[8] = 0;
}
void h_29(double *state, double *unused, double *out_8385240435486563070) {
   out_8385240435486563070[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8007883413890753541) {
   out_8007883413890753541[0] = 0;
   out_8007883413890753541[1] = 1;
   out_8007883413890753541[2] = 0;
   out_8007883413890753541[3] = 0;
   out_8007883413890753541[4] = 0;
   out_8007883413890753541[5] = 0;
   out_8007883413890753541[6] = 0;
   out_8007883413890753541[7] = 0;
   out_8007883413890753541[8] = 0;
}
void h_28(double *state, double *unused, double *out_8842799723036820222) {
   out_8842799723036820222[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2925484396821222967) {
   out_2925484396821222967[0] = 1;
   out_2925484396821222967[1] = 0;
   out_2925484396821222967[2] = 0;
   out_2925484396821222967[3] = 0;
   out_2925484396821222967[4] = 0;
   out_2925484396821222967[5] = 0;
   out_2925484396821222967[6] = 0;
   out_2925484396821222967[7] = 0;
   out_2925484396821222967[8] = 0;
}
void h_31(double *state, double *unused, double *out_5898842508611242163) {
   out_5898842508611242163[0] = state[8];
}
void H_31(double *state, double *unused, double *out_611607689961705030) {
   out_611607689961705030[0] = 0;
   out_611607689961705030[1] = 0;
   out_611607689961705030[2] = 0;
   out_611607689961705030[3] = 0;
   out_611607689961705030[4] = 0;
   out_611607689961705030[5] = 0;
   out_611607689961705030[6] = 0;
   out_611607689961705030[7] = 0;
   out_611607689961705030[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7601140416182293853) {
  err_fun(nom_x, delta_x, out_7601140416182293853);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8515902340586860735) {
  inv_err_fun(nom_x, true_x, out_8515902340586860735);
}
void car_H_mod_fun(double *state, double *out_2217032637436483966) {
  H_mod_fun(state, out_2217032637436483966);
}
void car_f_fun(double *state, double dt, double *out_3186535248829676437) {
  f_fun(state,  dt, out_3186535248829676437);
}
void car_F_fun(double *state, double dt, double *out_4268212592728321604) {
  F_fun(state,  dt, out_4268212592728321604);
}
void car_h_25(double *state, double *unused, double *out_5623648446326736274) {
  h_25(state, unused, out_5623648446326736274);
}
void car_H_25(double *state, double *unused, double *out_4979319111069112730) {
  H_25(state, unused, out_4979319111069112730);
}
void car_h_24(double *state, double *unused, double *out_5657381027351914870) {
  h_24(state, unused, out_5657381027351914870);
}
void car_H_24(double *state, double *unused, double *out_7156533534676262703) {
  H_24(state, unused, out_7156533534676262703);
}
void car_h_30(double *state, double *unused, double *out_1986198918072713924) {
  h_30(state, unused, out_1986198918072713924);
}
void car_H_30(double *state, double *unused, double *out_7497652069576361357) {
  H_30(state, unused, out_7497652069576361357);
}
void car_h_26(double *state, double *unused, double *out_7664235691370840552) {
  h_26(state, unused, out_7664235691370840552);
}
void car_H_26(double *state, double *unused, double *out_1237815792195056506) {
  H_26(state, unused, out_1237815792195056506);
}
void car_h_27(double *state, double *unused, double *out_8660434497771068959) {
  h_27(state, unused, out_8660434497771068959);
}
void car_H_27(double *state, double *unused, double *out_5322888757775936446) {
  H_27(state, unused, out_5322888757775936446);
}
void car_h_29(double *state, double *unused, double *out_8385240435486563070) {
  h_29(state, unused, out_8385240435486563070);
}
void car_H_29(double *state, double *unused, double *out_8007883413890753541) {
  H_29(state, unused, out_8007883413890753541);
}
void car_h_28(double *state, double *unused, double *out_8842799723036820222) {
  h_28(state, unused, out_8842799723036820222);
}
void car_H_28(double *state, double *unused, double *out_2925484396821222967) {
  H_28(state, unused, out_2925484396821222967);
}
void car_h_31(double *state, double *unused, double *out_5898842508611242163) {
  h_31(state, unused, out_5898842508611242163);
}
void car_H_31(double *state, double *unused, double *out_611607689961705030) {
  H_31(state, unused, out_611607689961705030);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
