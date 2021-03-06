/* Include files */

#include <stddef.h>
#include "blas.h"
#include "JointSpaceControl_CorrectInertia_sfun.h"
#include "c2_JointSpaceControl_CorrectInertia.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "JointSpaceControl_CorrectInertia_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[33] = { "theta_1", "theta_2",
  "theta_3", "theta_4", "theta_5", "theta_6", "r1_c1", "r2_c2", "r3_c3", "r4_c4",
  "r5_c5", "r6_c6", "R1", "R2", "R3", "R4", "R5", "R6", "d1", "d2", "d3", "d4",
  "d5", "d6", "nargin", "nargout", "q", "r0_c1", "r0_c2", "r0_c3", "r0_c4",
  "r0_c5", "r0_c6" };

/* Function Declarations */
static void initialize_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void initialize_params_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void enable_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void disable_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void set_sim_state_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void sf_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void c2_chartstep_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void initSimStructsc2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void registerMessagesc2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_r0_c6, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[17]);
static void c2_eml_scalar_eg(SFc2_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_JointSpaceControl_CorrectInertia, const char_T
   *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_JointSpaceControl_CorrectInertia = 0U;
}

static void initialize_params_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void enable_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[3];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  real_T c2_c_u[3];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i3;
  real_T c2_d_u[3];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i4;
  real_T c2_e_u[3];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i5;
  real_T c2_f_u[3];
  const mxArray *c2_g_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T (*c2_r0_c6)[3];
  real_T (*c2_r0_c5)[3];
  real_T (*c2_r0_c4)[3];
  real_T (*c2_r0_c3)[3];
  real_T (*c2_r0_c2)[3];
  real_T (*c2_r0_c1)[3];
  c2_r0_c6 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_r0_c5 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_r0_c4 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_r0_c3 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_r0_c2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_r0_c1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(7), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_u[c2_i0] = (*c2_r0_c1)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_r0_c2)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    c2_c_u[c2_i2] = (*c2_r0_c3)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_d_u[c2_i3] = (*c2_r0_c4)[c2_i3];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_e_u[c2_i4] = (*c2_r0_c5)[c2_i4];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_f_u[c2_i5] = (*c2_r0_c6)[c2_i5];
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_hoistedGlobal =
    chartInstance->c2_is_active_c2_JointSpaceControl_CorrectInertia;
  c2_g_u = c2_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i6;
  real_T c2_dv1[3];
  int32_T c2_i7;
  real_T c2_dv2[3];
  int32_T c2_i8;
  real_T c2_dv3[3];
  int32_T c2_i9;
  real_T c2_dv4[3];
  int32_T c2_i10;
  real_T c2_dv5[3];
  int32_T c2_i11;
  real_T (*c2_r0_c1)[3];
  real_T (*c2_r0_c2)[3];
  real_T (*c2_r0_c3)[3];
  real_T (*c2_r0_c4)[3];
  real_T (*c2_r0_c5)[3];
  real_T (*c2_r0_c6)[3];
  c2_r0_c6 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_r0_c5 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_r0_c4 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_r0_c3 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_r0_c2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_r0_c1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "r0_c1", c2_dv0);
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    (*c2_r0_c1)[c2_i6] = c2_dv0[c2_i6];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                      "r0_c2", c2_dv1);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    (*c2_r0_c2)[c2_i7] = c2_dv1[c2_i7];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
                      "r0_c3", c2_dv2);
  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    (*c2_r0_c3)[c2_i8] = c2_dv2[c2_i8];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                      "r0_c4", c2_dv3);
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    (*c2_r0_c4)[c2_i9] = c2_dv3[c2_i9];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
                      "r0_c5", c2_dv4);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    (*c2_r0_c5)[c2_i10] = c2_dv4[c2_i10];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
                      "r0_c6", c2_dv5);
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    (*c2_r0_c6)[c2_i11] = c2_dv5[c2_i11];
  }

  chartInstance->c2_is_active_c2_JointSpaceControl_CorrectInertia =
    c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
    "is_active_c2_JointSpaceControl_CorrectInertia");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_JointSpaceControl_CorrectInertia(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void sf_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  real_T (*c2_r0_c6)[3];
  real_T (*c2_r0_c5)[3];
  real_T (*c2_r0_c4)[3];
  real_T (*c2_r0_c3)[3];
  real_T (*c2_r0_c2)[3];
  real_T (*c2_r0_c1)[3];
  real_T (*c2_q)[6];
  c2_r0_c6 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_r0_c5 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_r0_c4 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_r0_c3 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_r0_c2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_r0_c1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i12 = 0; c2_i12 < 6; c2_i12++) {
    _SFD_DATA_RANGE_CHECK((*c2_q)[c2_i12], 0U);
  }

  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    _SFD_DATA_RANGE_CHECK((*c2_r0_c1)[c2_i13], 1U);
  }

  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    _SFD_DATA_RANGE_CHECK((*c2_r0_c2)[c2_i14], 2U);
  }

  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    _SFD_DATA_RANGE_CHECK((*c2_r0_c3)[c2_i15], 3U);
  }

  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    _SFD_DATA_RANGE_CHECK((*c2_r0_c4)[c2_i16], 4U);
  }

  for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
    _SFD_DATA_RANGE_CHECK((*c2_r0_c5)[c2_i17], 5U);
  }

  for (c2_i18 = 0; c2_i18 < 3; c2_i18++) {
    _SFD_DATA_RANGE_CHECK((*c2_r0_c6)[c2_i18], 6U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_JointSpaceControl_CorrectInertia(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_JointSpaceControl_CorrectInertiaMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
  int32_T c2_i19;
  real_T c2_q[6];
  uint32_T c2_debug_family_var_map[33];
  real_T c2_theta_1;
  real_T c2_theta_2;
  real_T c2_theta_3;
  real_T c2_theta_4;
  real_T c2_theta_5;
  real_T c2_theta_6;
  real_T c2_r1_c1[3];
  real_T c2_r2_c2[3];
  real_T c2_r3_c3[3];
  real_T c2_r4_c4[3];
  real_T c2_r5_c5[3];
  real_T c2_r6_c6[3];
  real_T c2_R1[9];
  real_T c2_R2[9];
  real_T c2_R3[9];
  real_T c2_R4[9];
  real_T c2_R5[9];
  real_T c2_R6[9];
  real_T c2_d1[3];
  real_T c2_d2[3];
  real_T c2_d3[3];
  real_T c2_d4[3];
  real_T c2_d5[3];
  real_T c2_d6[3];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 6.0;
  real_T c2_r0_c1[3];
  real_T c2_r0_c2[3];
  real_T c2_r0_c3[3];
  real_T c2_r0_c4[3];
  real_T c2_r0_c5[3];
  real_T c2_r0_c6[3];
  int32_T c2_i20;
  static real_T c2_dv6[3] = { 0.0, -0.02561, 0.00193 };

  int32_T c2_i21;
  static real_T c2_dv7[3] = { 0.2125, 0.0, 0.11336 };

  int32_T c2_i22;
  static real_T c2_dv8[3] = { 0.11993, 0.0, 0.0265 };

  int32_T c2_i23;
  static real_T c2_dv9[3] = { 0.0, -0.0018, 0.01634 };

  int32_T c2_i24;
  static real_T c2_dv10[3] = { 0.0, 0.0018, 0.01634 };

  int32_T c2_i25;
  static real_T c2_dv11[3] = { 0.0, 0.0, -0.001159 };

  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  int32_T c2_i26;
  int32_T c2_i27;
  static real_T c2_dv12[3] = { 0.0, 1.0, 0.0 };

  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_c_y;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_d_y;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_e_y;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_f_y;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_h_a;
  real_T c2_h_b;
  real_T c2_h_y;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_i_a;
  real_T c2_i_b;
  real_T c2_i_y;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_j_a;
  real_T c2_j_b;
  real_T c2_j_y;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_k_a;
  real_T c2_k_b;
  real_T c2_k_y;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_l_a;
  real_T c2_l_b;
  real_T c2_l_y;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_ic_x;
  real_T c2_jc_x;
  real_T c2_kc_x;
  real_T c2_lc_x;
  real_T c2_m_a;
  real_T c2_m_b;
  real_T c2_m_y;
  real_T c2_mc_x;
  real_T c2_nc_x;
  real_T c2_n_a;
  real_T c2_n_b;
  real_T c2_n_y;
  real_T c2_oc_x;
  real_T c2_pc_x;
  real_T c2_qc_x;
  real_T c2_rc_x;
  real_T c2_o_a;
  real_T c2_o_b;
  real_T c2_o_y;
  real_T c2_sc_x;
  real_T c2_tc_x;
  real_T c2_p_a;
  real_T c2_p_b;
  real_T c2_p_y;
  real_T c2_uc_x;
  real_T c2_vc_x;
  real_T c2_wc_x;
  real_T c2_xc_x;
  real_T c2_q_a;
  real_T c2_q_b;
  real_T c2_q_y;
  real_T c2_yc_x;
  real_T c2_ad_x;
  real_T c2_r_a;
  real_T c2_r_b;
  real_T c2_r_y;
  real_T c2_bd_x;
  real_T c2_cd_x;
  real_T c2_dd_x;
  real_T c2_ed_x;
  real_T c2_s_a;
  real_T c2_s_b;
  real_T c2_s_y;
  real_T c2_fd_x;
  real_T c2_gd_x;
  real_T c2_t_a;
  real_T c2_t_b;
  real_T c2_t_y;
  real_T c2_hd_x;
  real_T c2_id_x;
  real_T c2_jd_x;
  real_T c2_kd_x;
  real_T c2_ld_x;
  real_T c2_md_x;
  real_T c2_u_a;
  real_T c2_u_b;
  real_T c2_u_y;
  real_T c2_nd_x;
  real_T c2_od_x;
  real_T c2_pd_x;
  real_T c2_qd_x;
  real_T c2_v_a;
  real_T c2_v_b;
  real_T c2_v_y;
  real_T c2_rd_x;
  real_T c2_sd_x;
  real_T c2_td_x;
  real_T c2_ud_x;
  real_T c2_w_a;
  real_T c2_w_b;
  real_T c2_w_y;
  real_T c2_vd_x;
  real_T c2_wd_x;
  real_T c2_xd_x;
  real_T c2_yd_x;
  real_T c2_x_a;
  real_T c2_x_b;
  real_T c2_x_y;
  real_T c2_ae_x;
  real_T c2_be_x;
  real_T c2_ce_x;
  real_T c2_de_x;
  real_T c2_ee_x;
  real_T c2_fe_x;
  real_T c2_y_a;
  real_T c2_y_b;
  real_T c2_y_y;
  real_T c2_ge_x;
  real_T c2_he_x;
  real_T c2_ab_a;
  real_T c2_ab_b;
  real_T c2_ab_y;
  real_T c2_ie_x;
  real_T c2_je_x;
  real_T c2_ke_x;
  real_T c2_le_x;
  real_T c2_bb_a;
  real_T c2_bb_b;
  real_T c2_bb_y;
  real_T c2_me_x;
  real_T c2_ne_x;
  real_T c2_cb_a;
  real_T c2_cb_b;
  real_T c2_cb_y;
  real_T c2_db_a;
  real_T c2_db_b;
  real_T c2_db_y;
  real_T c2_oe_x;
  real_T c2_pe_x;
  real_T c2_qe_x;
  real_T c2_re_x;
  real_T c2_se_x;
  real_T c2_te_x;
  real_T c2_eb_a;
  real_T c2_eb_b;
  real_T c2_eb_y;
  real_T c2_ue_x;
  real_T c2_ve_x;
  real_T c2_fb_a;
  real_T c2_fb_b;
  real_T c2_fb_y;
  real_T c2_we_x;
  real_T c2_xe_x;
  real_T c2_ye_x;
  real_T c2_af_x;
  real_T c2_gb_a;
  real_T c2_gb_b;
  real_T c2_gb_y;
  real_T c2_bf_x;
  real_T c2_cf_x;
  real_T c2_hb_a;
  real_T c2_hb_b;
  real_T c2_hb_y;
  real_T c2_ib_a;
  real_T c2_ib_b;
  real_T c2_ib_y;
  real_T c2_df_x;
  real_T c2_ef_x;
  real_T c2_ff_x;
  real_T c2_gf_x;
  real_T c2_hf_x;
  real_T c2_if_x;
  real_T c2_jf_x;
  real_T c2_kf_x;
  real_T c2_jb_a;
  real_T c2_jb_b;
  real_T c2_jb_y;
  real_T c2_lf_x;
  real_T c2_mf_x;
  real_T c2_kb_a;
  real_T c2_kb_b;
  real_T c2_kb_y;
  real_T c2_nf_x;
  real_T c2_of_x;
  real_T c2_pf_x;
  real_T c2_qf_x;
  real_T c2_lb_a;
  real_T c2_lb_b;
  real_T c2_lb_y;
  real_T c2_rf_x;
  real_T c2_sf_x;
  real_T c2_mb_a;
  real_T c2_mb_b;
  real_T c2_mb_y;
  real_T c2_nb_a;
  real_T c2_nb_b;
  real_T c2_nb_y;
  real_T c2_tf_x;
  real_T c2_uf_x;
  real_T c2_vf_x;
  real_T c2_wf_x;
  real_T c2_xf_x;
  real_T c2_yf_x;
  real_T c2_ob_a;
  real_T c2_ob_b;
  real_T c2_ob_y;
  real_T c2_ag_x;
  real_T c2_bg_x;
  real_T c2_pb_a;
  real_T c2_pb_b;
  real_T c2_pb_y;
  real_T c2_cg_x;
  real_T c2_dg_x;
  real_T c2_eg_x;
  real_T c2_fg_x;
  real_T c2_qb_a;
  real_T c2_qb_b;
  real_T c2_qb_y;
  real_T c2_gg_x;
  real_T c2_hg_x;
  real_T c2_rb_a;
  real_T c2_rb_b;
  real_T c2_rb_y;
  real_T c2_sb_a;
  real_T c2_sb_b;
  real_T c2_sb_y;
  real_T c2_ig_x;
  real_T c2_jg_x;
  real_T c2_kg_x;
  real_T c2_lg_x;
  real_T c2_mg_x;
  real_T c2_ng_x;
  real_T c2_tb_a;
  real_T c2_tb_b;
  real_T c2_tb_y;
  real_T c2_og_x;
  real_T c2_pg_x;
  real_T c2_ub_a;
  real_T c2_ub_b;
  real_T c2_ub_y;
  real_T c2_qg_x;
  real_T c2_rg_x;
  real_T c2_sg_x;
  real_T c2_tg_x;
  real_T c2_vb_a;
  real_T c2_vb_b;
  real_T c2_vb_y;
  real_T c2_ug_x;
  real_T c2_vg_x;
  real_T c2_wb_a;
  real_T c2_wb_b;
  real_T c2_wb_y;
  real_T c2_xb_a;
  real_T c2_xb_b;
  real_T c2_xb_y;
  real_T c2_wg_x;
  real_T c2_xg_x;
  real_T c2_yg_x;
  real_T c2_ah_x;
  real_T c2_bh_x;
  real_T c2_ch_x;
  real_T c2_yb_a;
  real_T c2_yb_b;
  real_T c2_yb_y;
  real_T c2_dh_x;
  real_T c2_eh_x;
  real_T c2_ac_a;
  real_T c2_ac_b;
  real_T c2_ac_y;
  real_T c2_fh_x;
  real_T c2_gh_x;
  real_T c2_hh_x;
  real_T c2_ih_x;
  real_T c2_bc_a;
  real_T c2_bc_b;
  real_T c2_bc_y;
  real_T c2_jh_x;
  real_T c2_kh_x;
  real_T c2_cc_a;
  real_T c2_cc_b;
  real_T c2_cc_y;
  real_T c2_dc_a;
  real_T c2_dc_b;
  real_T c2_dc_y;
  real_T c2_lh_x;
  real_T c2_mh_x;
  real_T c2_nh_x;
  real_T c2_oh_x;
  real_T c2_ph_x;
  real_T c2_qh_x;
  real_T c2_rh_x;
  real_T c2_sh_x;
  real_T c2_ec_a;
  real_T c2_ec_b;
  real_T c2_ec_y;
  real_T c2_th_x;
  real_T c2_uh_x;
  real_T c2_fc_a;
  real_T c2_fc_b;
  real_T c2_fc_y;
  real_T c2_vh_x;
  real_T c2_wh_x;
  real_T c2_xh_x;
  real_T c2_yh_x;
  real_T c2_gc_a;
  real_T c2_gc_b;
  real_T c2_gc_y;
  real_T c2_ai_x;
  real_T c2_bi_x;
  real_T c2_hc_a;
  real_T c2_hc_b;
  real_T c2_hc_y;
  real_T c2_ic_a;
  real_T c2_ic_b;
  real_T c2_ic_y;
  real_T c2_ci_x;
  real_T c2_di_x;
  real_T c2_ei_x;
  real_T c2_fi_x;
  real_T c2_gi_x;
  real_T c2_hi_x;
  real_T c2_jc_a;
  real_T c2_jc_b;
  real_T c2_jc_y;
  real_T c2_ii_x;
  real_T c2_ji_x;
  real_T c2_kc_a;
  real_T c2_kc_b;
  real_T c2_kc_y;
  real_T c2_ki_x;
  real_T c2_li_x;
  real_T c2_mi_x;
  real_T c2_ni_x;
  real_T c2_lc_a;
  real_T c2_lc_b;
  real_T c2_lc_y;
  real_T c2_oi_x;
  real_T c2_pi_x;
  real_T c2_mc_a;
  real_T c2_mc_b;
  real_T c2_mc_y;
  real_T c2_nc_a;
  real_T c2_nc_b;
  real_T c2_nc_y;
  real_T c2_qi_x;
  real_T c2_ri_x;
  real_T c2_si_x;
  real_T c2_ti_x;
  real_T c2_ui_x;
  real_T c2_vi_x;
  real_T c2_oc_a;
  real_T c2_oc_b;
  real_T c2_oc_y;
  real_T c2_wi_x;
  real_T c2_xi_x;
  real_T c2_yi_x;
  real_T c2_aj_x;
  real_T c2_pc_a;
  real_T c2_pc_b;
  real_T c2_pc_y;
  real_T c2_qc_a;
  real_T c2_qc_b;
  real_T c2_qc_y;
  real_T c2_bj_x;
  real_T c2_cj_x;
  real_T c2_dj_x;
  real_T c2_ej_x;
  real_T c2_fj_x;
  real_T c2_gj_x;
  real_T c2_rc_a;
  real_T c2_rc_b;
  real_T c2_rc_y;
  real_T c2_hj_x;
  real_T c2_ij_x;
  real_T c2_jj_x;
  real_T c2_kj_x;
  real_T c2_sc_a;
  real_T c2_sc_b;
  real_T c2_sc_y;
  real_T c2_tc_a;
  real_T c2_tc_b;
  real_T c2_tc_y;
  real_T c2_lj_x;
  real_T c2_mj_x;
  real_T c2_nj_x;
  real_T c2_oj_x;
  real_T c2_pj_x;
  real_T c2_qj_x;
  real_T c2_uc_a;
  real_T c2_uc_b;
  real_T c2_uc_y;
  real_T c2_rj_x;
  real_T c2_sj_x;
  real_T c2_tj_x;
  real_T c2_uj_x;
  real_T c2_vc_a;
  real_T c2_vc_b;
  real_T c2_vc_y;
  real_T c2_wc_a;
  real_T c2_wc_b;
  real_T c2_wc_y;
  real_T c2_vj_x;
  real_T c2_wj_x;
  real_T c2_xj_x;
  real_T c2_yj_x;
  real_T c2_ak_x;
  real_T c2_bk_x;
  real_T c2_xc_a;
  real_T c2_xc_b;
  real_T c2_xc_y;
  real_T c2_ck_x;
  real_T c2_dk_x;
  real_T c2_ek_x;
  real_T c2_fk_x;
  real_T c2_yc_a;
  real_T c2_yc_b;
  real_T c2_yc_y;
  real_T c2_ad_a;
  real_T c2_ad_b;
  real_T c2_ad_y;
  real_T c2_gk_x;
  real_T c2_hk_x;
  real_T c2_ik_x;
  real_T c2_jk_x;
  real_T c2_bd_a;
  real_T c2_bd_b;
  real_T c2_bd_y;
  real_T c2_kk_x;
  real_T c2_lk_x;
  real_T c2_mk_x;
  real_T c2_nk_x;
  real_T c2_ok_x;
  real_T c2_pk_x;
  real_T c2_qk_x;
  real_T c2_rk_x;
  real_T c2_cd_a;
  real_T c2_cd_b;
  real_T c2_cd_y;
  real_T c2_sk_x;
  real_T c2_tk_x;
  real_T c2_dd_a;
  real_T c2_dd_b;
  real_T c2_dd_y;
  real_T c2_uk_x;
  real_T c2_vk_x;
  real_T c2_wk_x;
  real_T c2_xk_x;
  real_T c2_ed_a;
  real_T c2_ed_b;
  real_T c2_ed_y;
  real_T c2_yk_x;
  real_T c2_al_x;
  real_T c2_fd_a;
  real_T c2_fd_b;
  real_T c2_fd_y;
  real_T c2_gd_a;
  real_T c2_gd_b;
  real_T c2_gd_y;
  real_T c2_bl_x;
  real_T c2_cl_x;
  real_T c2_dl_x;
  real_T c2_el_x;
  real_T c2_fl_x;
  real_T c2_gl_x;
  real_T c2_hd_a;
  real_T c2_hd_b;
  real_T c2_hd_y;
  real_T c2_hl_x;
  real_T c2_il_x;
  real_T c2_id_a;
  real_T c2_id_b;
  real_T c2_id_y;
  real_T c2_jl_x;
  real_T c2_kl_x;
  real_T c2_ll_x;
  real_T c2_ml_x;
  real_T c2_jd_a;
  real_T c2_jd_b;
  real_T c2_jd_y;
  real_T c2_nl_x;
  real_T c2_ol_x;
  real_T c2_kd_a;
  real_T c2_kd_b;
  real_T c2_kd_y;
  real_T c2_ld_a;
  real_T c2_ld_b;
  real_T c2_ld_y;
  real_T c2_md_a;
  real_T c2_md_b;
  real_T c2_md_y;
  real_T c2_pl_x;
  real_T c2_ql_x;
  real_T c2_rl_x;
  real_T c2_sl_x;
  real_T c2_tl_x;
  real_T c2_ul_x;
  real_T c2_nd_a;
  real_T c2_nd_b;
  real_T c2_nd_y;
  real_T c2_vl_x;
  real_T c2_wl_x;
  real_T c2_od_a;
  real_T c2_od_b;
  real_T c2_od_y;
  real_T c2_xl_x;
  real_T c2_yl_x;
  real_T c2_am_x;
  real_T c2_bm_x;
  real_T c2_pd_a;
  real_T c2_pd_b;
  real_T c2_pd_y;
  real_T c2_cm_x;
  real_T c2_dm_x;
  real_T c2_qd_a;
  real_T c2_qd_b;
  real_T c2_qd_y;
  real_T c2_rd_a;
  real_T c2_rd_b;
  real_T c2_rd_y;
  real_T c2_em_x;
  real_T c2_fm_x;
  real_T c2_gm_x;
  real_T c2_hm_x;
  real_T c2_im_x;
  real_T c2_jm_x;
  real_T c2_sd_a;
  real_T c2_sd_b;
  real_T c2_sd_y;
  real_T c2_km_x;
  real_T c2_lm_x;
  real_T c2_td_a;
  real_T c2_td_b;
  real_T c2_td_y;
  real_T c2_mm_x;
  real_T c2_nm_x;
  real_T c2_om_x;
  real_T c2_pm_x;
  real_T c2_ud_a;
  real_T c2_ud_b;
  real_T c2_ud_y;
  real_T c2_qm_x;
  real_T c2_rm_x;
  real_T c2_vd_a;
  real_T c2_vd_b;
  real_T c2_vd_y;
  real_T c2_wd_a;
  real_T c2_wd_b;
  real_T c2_wd_y;
  real_T c2_sm_x;
  real_T c2_tm_x;
  real_T c2_um_x;
  real_T c2_vm_x;
  real_T c2_xd_a;
  real_T c2_xd_b;
  real_T c2_xd_y;
  real_T c2_wm_x;
  real_T c2_xm_x;
  real_T c2_ym_x;
  real_T c2_an_x;
  real_T c2_bn_x;
  real_T c2_cn_x;
  real_T c2_dn_x;
  real_T c2_en_x;
  real_T c2_yd_a;
  real_T c2_yd_b;
  real_T c2_yd_y;
  real_T c2_fn_x;
  real_T c2_gn_x;
  real_T c2_ae_a;
  real_T c2_ae_b;
  real_T c2_ae_y;
  real_T c2_hn_x;
  real_T c2_in_x;
  real_T c2_jn_x;
  real_T c2_kn_x;
  real_T c2_be_a;
  real_T c2_be_b;
  real_T c2_be_y;
  real_T c2_ln_x;
  real_T c2_mn_x;
  real_T c2_ce_a;
  real_T c2_ce_b;
  real_T c2_ce_y;
  real_T c2_de_a;
  real_T c2_de_b;
  real_T c2_de_y;
  real_T c2_nn_x;
  real_T c2_on_x;
  real_T c2_pn_x;
  real_T c2_qn_x;
  real_T c2_rn_x;
  real_T c2_sn_x;
  real_T c2_ee_a;
  real_T c2_ee_b;
  real_T c2_ee_y;
  real_T c2_tn_x;
  real_T c2_un_x;
  real_T c2_fe_a;
  real_T c2_fe_b;
  real_T c2_fe_y;
  real_T c2_vn_x;
  real_T c2_wn_x;
  real_T c2_xn_x;
  real_T c2_yn_x;
  real_T c2_ge_a;
  real_T c2_ge_b;
  real_T c2_ge_y;
  real_T c2_ao_x;
  real_T c2_bo_x;
  real_T c2_he_a;
  real_T c2_he_b;
  real_T c2_he_y;
  real_T c2_ie_a;
  real_T c2_ie_b;
  real_T c2_ie_y;
  real_T c2_je_a;
  real_T c2_je_b;
  real_T c2_je_y;
  real_T c2_co_x;
  real_T c2_do_x;
  real_T c2_eo_x;
  real_T c2_fo_x;
  real_T c2_ke_a;
  real_T c2_ke_b;
  real_T c2_ke_y;
  real_T c2_go_x;
  real_T c2_ho_x;
  real_T c2_io_x;
  real_T c2_jo_x;
  real_T c2_ko_x;
  real_T c2_lo_x;
  real_T c2_mo_x;
  real_T c2_no_x;
  real_T c2_le_a;
  real_T c2_le_b;
  real_T c2_le_y;
  real_T c2_oo_x;
  real_T c2_po_x;
  real_T c2_me_a;
  real_T c2_me_b;
  real_T c2_me_y;
  real_T c2_qo_x;
  real_T c2_ro_x;
  real_T c2_so_x;
  real_T c2_to_x;
  real_T c2_ne_a;
  real_T c2_ne_b;
  real_T c2_ne_y;
  real_T c2_uo_x;
  real_T c2_vo_x;
  real_T c2_oe_a;
  real_T c2_oe_b;
  real_T c2_oe_y;
  real_T c2_pe_a;
  real_T c2_pe_b;
  real_T c2_pe_y;
  real_T c2_wo_x;
  real_T c2_xo_x;
  real_T c2_yo_x;
  real_T c2_ap_x;
  real_T c2_bp_x;
  real_T c2_cp_x;
  real_T c2_qe_a;
  real_T c2_qe_b;
  real_T c2_qe_y;
  real_T c2_dp_x;
  real_T c2_ep_x;
  real_T c2_re_a;
  real_T c2_re_b;
  real_T c2_re_y;
  real_T c2_fp_x;
  real_T c2_gp_x;
  real_T c2_hp_x;
  real_T c2_ip_x;
  real_T c2_se_a;
  real_T c2_se_b;
  real_T c2_se_y;
  real_T c2_jp_x;
  real_T c2_kp_x;
  real_T c2_te_a;
  real_T c2_te_b;
  real_T c2_te_y;
  real_T c2_ue_a;
  real_T c2_ue_b;
  real_T c2_ue_y;
  real_T c2_ve_a;
  real_T c2_ve_b;
  real_T c2_ve_y;
  real_T c2_lp_x;
  real_T c2_mp_x;
  real_T c2_np_x;
  real_T c2_op_x;
  real_T c2_pp_x;
  real_T c2_qp_x;
  real_T c2_we_a;
  real_T c2_we_b;
  real_T c2_we_y;
  real_T c2_rp_x;
  real_T c2_sp_x;
  real_T c2_xe_a;
  real_T c2_xe_b;
  real_T c2_xe_y;
  real_T c2_tp_x;
  real_T c2_up_x;
  real_T c2_vp_x;
  real_T c2_wp_x;
  real_T c2_ye_a;
  real_T c2_ye_b;
  real_T c2_ye_y;
  real_T c2_xp_x;
  real_T c2_yp_x;
  real_T c2_af_a;
  real_T c2_af_b;
  real_T c2_af_y;
  real_T c2_bf_a;
  real_T c2_bf_b;
  real_T c2_bf_y;
  real_T c2_aq_x;
  real_T c2_bq_x;
  real_T c2_cq_x;
  real_T c2_dq_x;
  real_T c2_eq_x;
  real_T c2_fq_x;
  real_T c2_cf_a;
  real_T c2_cf_b;
  real_T c2_cf_y;
  real_T c2_gq_x;
  real_T c2_hq_x;
  real_T c2_df_a;
  real_T c2_df_b;
  real_T c2_df_y;
  real_T c2_iq_x;
  real_T c2_jq_x;
  real_T c2_kq_x;
  real_T c2_lq_x;
  real_T c2_ef_a;
  real_T c2_ef_b;
  real_T c2_ef_y;
  real_T c2_mq_x;
  real_T c2_nq_x;
  real_T c2_ff_a;
  real_T c2_ff_b;
  real_T c2_ff_y;
  real_T c2_gf_a;
  real_T c2_gf_b;
  real_T c2_gf_y;
  real_T c2_oq_x;
  real_T c2_pq_x;
  real_T c2_qq_x;
  real_T c2_rq_x;
  real_T c2_sq_x;
  real_T c2_tq_x;
  real_T c2_uq_x;
  real_T c2_vq_x;
  real_T c2_hf_a;
  real_T c2_hf_b;
  real_T c2_hf_y;
  real_T c2_wq_x;
  real_T c2_xq_x;
  real_T c2_if_a;
  real_T c2_if_b;
  real_T c2_if_y;
  real_T c2_yq_x;
  real_T c2_ar_x;
  real_T c2_br_x;
  real_T c2_cr_x;
  real_T c2_jf_a;
  real_T c2_jf_b;
  real_T c2_jf_y;
  real_T c2_dr_x;
  real_T c2_er_x;
  real_T c2_kf_a;
  real_T c2_kf_b;
  real_T c2_kf_y;
  real_T c2_lf_a;
  real_T c2_lf_b;
  real_T c2_lf_y;
  real_T c2_fr_x;
  real_T c2_gr_x;
  real_T c2_hr_x;
  real_T c2_ir_x;
  real_T c2_jr_x;
  real_T c2_kr_x;
  real_T c2_mf_a;
  real_T c2_mf_b;
  real_T c2_mf_y;
  real_T c2_lr_x;
  real_T c2_mr_x;
  real_T c2_nf_a;
  real_T c2_nf_b;
  real_T c2_nf_y;
  real_T c2_nr_x;
  real_T c2_or_x;
  real_T c2_pr_x;
  real_T c2_qr_x;
  real_T c2_of_a;
  real_T c2_of_b;
  real_T c2_of_y;
  real_T c2_rr_x;
  real_T c2_sr_x;
  real_T c2_pf_a;
  real_T c2_pf_b;
  real_T c2_pf_y;
  real_T c2_qf_a;
  real_T c2_qf_b;
  real_T c2_qf_y;
  real_T c2_rf_a;
  real_T c2_rf_b;
  real_T c2_rf_y;
  real_T c2_tr_x;
  real_T c2_ur_x;
  real_T c2_vr_x;
  real_T c2_wr_x;
  real_T c2_sf_a;
  real_T c2_sf_b;
  real_T c2_sf_y;
  real_T c2_xr_x;
  real_T c2_yr_x;
  real_T c2_as_x;
  real_T c2_bs_x;
  real_T c2_cs_x;
  real_T c2_ds_x;
  real_T c2_es_x;
  real_T c2_fs_x;
  real_T c2_tf_a;
  real_T c2_tf_b;
  real_T c2_tf_y;
  real_T c2_gs_x;
  real_T c2_hs_x;
  real_T c2_is_x;
  real_T c2_js_x;
  real_T c2_uf_a;
  real_T c2_uf_b;
  real_T c2_uf_y;
  real_T c2_vf_a;
  real_T c2_vf_b;
  real_T c2_vf_y;
  real_T c2_ks_x;
  real_T c2_ls_x;
  real_T c2_ms_x;
  real_T c2_ns_x;
  real_T c2_os_x;
  real_T c2_ps_x;
  real_T c2_wf_a;
  real_T c2_wf_b;
  real_T c2_wf_y;
  real_T c2_qs_x;
  real_T c2_rs_x;
  real_T c2_ss_x;
  real_T c2_ts_x;
  real_T c2_xf_a;
  real_T c2_xf_b;
  real_T c2_xf_y;
  real_T c2_yf_a;
  real_T c2_yf_b;
  real_T c2_yf_y;
  real_T c2_ag_a;
  real_T c2_ag_b;
  real_T c2_ag_y;
  real_T c2_us_x;
  real_T c2_vs_x;
  real_T c2_ws_x;
  real_T c2_xs_x;
  real_T c2_ys_x;
  real_T c2_at_x;
  real_T c2_bg_a;
  real_T c2_bg_b;
  real_T c2_bg_y;
  real_T c2_bt_x;
  real_T c2_ct_x;
  real_T c2_dt_x;
  real_T c2_et_x;
  real_T c2_cg_a;
  real_T c2_cg_b;
  real_T c2_cg_y;
  real_T c2_dg_a;
  real_T c2_dg_b;
  real_T c2_dg_y;
  real_T c2_ft_x;
  real_T c2_gt_x;
  real_T c2_ht_x;
  real_T c2_it_x;
  real_T c2_jt_x;
  real_T c2_kt_x;
  real_T c2_eg_a;
  real_T c2_eg_b;
  real_T c2_eg_y;
  real_T c2_lt_x;
  real_T c2_mt_x;
  real_T c2_nt_x;
  real_T c2_ot_x;
  real_T c2_fg_a;
  real_T c2_fg_b;
  real_T c2_fg_y;
  real_T c2_gg_a;
  real_T c2_gg_b;
  real_T c2_gg_y;
  real_T c2_pt_x;
  real_T c2_qt_x;
  real_T c2_rt_x;
  real_T c2_st_x;
  real_T c2_tt_x;
  real_T c2_ut_x;
  real_T c2_vt_x;
  real_T c2_wt_x;
  real_T c2_hg_a;
  real_T c2_hg_b;
  real_T c2_hg_y;
  real_T c2_xt_x;
  real_T c2_yt_x;
  real_T c2_au_x;
  real_T c2_bu_x;
  real_T c2_ig_a;
  real_T c2_ig_b;
  real_T c2_ig_y;
  real_T c2_jg_a;
  real_T c2_jg_b;
  real_T c2_jg_y;
  real_T c2_cu_x;
  real_T c2_du_x;
  real_T c2_eu_x;
  real_T c2_fu_x;
  real_T c2_gu_x;
  real_T c2_hu_x;
  real_T c2_kg_a;
  real_T c2_kg_b;
  real_T c2_kg_y;
  real_T c2_iu_x;
  real_T c2_ju_x;
  real_T c2_ku_x;
  real_T c2_lu_x;
  real_T c2_lg_a;
  real_T c2_lg_b;
  real_T c2_lg_y;
  real_T c2_mg_a;
  real_T c2_mg_b;
  real_T c2_mg_y;
  real_T c2_ng_a;
  real_T c2_ng_b;
  real_T c2_ng_y;
  real_T c2_mu_x;
  real_T c2_nu_x;
  real_T c2_ou_x;
  real_T c2_pu_x;
  real_T c2_qu_x;
  real_T c2_ru_x;
  real_T c2_og_a;
  real_T c2_og_b;
  real_T c2_og_y;
  real_T c2_su_x;
  real_T c2_tu_x;
  real_T c2_uu_x;
  real_T c2_vu_x;
  real_T c2_wu_x;
  real_T c2_xu_x;
  real_T c2_yu_x;
  real_T c2_av_x;
  real_T c2_pg_a;
  real_T c2_pg_b;
  real_T c2_pg_y;
  real_T c2_bv_x;
  real_T c2_cv_x;
  real_T c2_qg_a;
  real_T c2_qg_b;
  real_T c2_qg_y;
  real_T c2_dv_x;
  real_T c2_ev_x;
  real_T c2_fv_x;
  real_T c2_gv_x;
  real_T c2_rg_a;
  real_T c2_rg_b;
  real_T c2_rg_y;
  real_T c2_hv_x;
  real_T c2_iv_x;
  real_T c2_sg_a;
  real_T c2_sg_b;
  real_T c2_sg_y;
  real_T c2_tg_a;
  real_T c2_tg_b;
  real_T c2_tg_y;
  real_T c2_jv_x;
  real_T c2_kv_x;
  real_T c2_lv_x;
  real_T c2_mv_x;
  real_T c2_nv_x;
  real_T c2_ov_x;
  real_T c2_ug_a;
  real_T c2_ug_b;
  real_T c2_ug_y;
  real_T c2_pv_x;
  real_T c2_qv_x;
  real_T c2_vg_a;
  real_T c2_vg_b;
  real_T c2_vg_y;
  real_T c2_rv_x;
  real_T c2_sv_x;
  real_T c2_tv_x;
  real_T c2_uv_x;
  real_T c2_wg_a;
  real_T c2_wg_b;
  real_T c2_wg_y;
  real_T c2_vv_x;
  real_T c2_wv_x;
  real_T c2_xg_a;
  real_T c2_xg_b;
  real_T c2_xg_y;
  real_T c2_yg_a;
  real_T c2_yg_b;
  real_T c2_yg_y;
  real_T c2_ah_a;
  real_T c2_ah_b;
  real_T c2_ah_y;
  real_T c2_bh_a;
  real_T c2_bh_b;
  real_T c2_bh_y;
  real_T c2_xv_x;
  real_T c2_yv_x;
  real_T c2_aw_x;
  real_T c2_bw_x;
  real_T c2_cw_x;
  real_T c2_dw_x;
  real_T c2_ew_x;
  real_T c2_fw_x;
  real_T c2_ch_a;
  real_T c2_ch_b;
  real_T c2_ch_y;
  real_T c2_gw_x;
  real_T c2_hw_x;
  real_T c2_dh_a;
  real_T c2_dh_b;
  real_T c2_dh_y;
  real_T c2_iw_x;
  real_T c2_jw_x;
  real_T c2_kw_x;
  real_T c2_lw_x;
  real_T c2_eh_a;
  real_T c2_eh_b;
  real_T c2_eh_y;
  real_T c2_mw_x;
  real_T c2_nw_x;
  real_T c2_fh_a;
  real_T c2_fh_b;
  real_T c2_fh_y;
  real_T c2_gh_a;
  real_T c2_gh_b;
  real_T c2_gh_y;
  real_T c2_ow_x;
  real_T c2_pw_x;
  real_T c2_qw_x;
  real_T c2_rw_x;
  real_T c2_sw_x;
  real_T c2_tw_x;
  real_T c2_hh_a;
  real_T c2_hh_b;
  real_T c2_hh_y;
  real_T c2_uw_x;
  real_T c2_vw_x;
  real_T c2_ih_a;
  real_T c2_ih_b;
  real_T c2_ih_y;
  real_T c2_ww_x;
  real_T c2_xw_x;
  real_T c2_yw_x;
  real_T c2_ax_x;
  real_T c2_jh_a;
  real_T c2_jh_b;
  real_T c2_jh_y;
  real_T c2_bx_x;
  real_T c2_cx_x;
  real_T c2_kh_a;
  real_T c2_kh_b;
  real_T c2_kh_y;
  real_T c2_lh_a;
  real_T c2_lh_b;
  real_T c2_lh_y;
  real_T c2_mh_a;
  real_T c2_mh_b;
  real_T c2_mh_y;
  real_T c2_dx_x;
  real_T c2_ex_x;
  real_T c2_fx_x;
  real_T c2_gx_x;
  real_T c2_hx_x;
  real_T c2_ix_x;
  real_T c2_nh_a;
  real_T c2_nh_b;
  real_T c2_nh_y;
  real_T c2_jx_x;
  real_T c2_kx_x;
  real_T c2_lx_x;
  real_T c2_mx_x;
  real_T c2_nx_x;
  real_T c2_ox_x;
  real_T c2_px_x;
  real_T c2_qx_x;
  real_T c2_oh_a;
  real_T c2_oh_b;
  real_T c2_oh_y;
  real_T c2_rx_x;
  real_T c2_sx_x;
  real_T c2_ph_a;
  real_T c2_ph_b;
  real_T c2_ph_y;
  real_T c2_tx_x;
  real_T c2_ux_x;
  real_T c2_vx_x;
  real_T c2_wx_x;
  real_T c2_qh_a;
  real_T c2_qh_b;
  real_T c2_qh_y;
  real_T c2_xx_x;
  real_T c2_yx_x;
  real_T c2_rh_a;
  real_T c2_rh_b;
  real_T c2_rh_y;
  real_T c2_sh_a;
  real_T c2_sh_b;
  real_T c2_sh_y;
  real_T c2_ay_x;
  real_T c2_by_x;
  real_T c2_cy_x;
  real_T c2_dy_x;
  real_T c2_ey_x;
  real_T c2_fy_x;
  real_T c2_th_a;
  real_T c2_th_b;
  real_T c2_th_y;
  real_T c2_gy_x;
  real_T c2_hy_x;
  real_T c2_uh_a;
  real_T c2_uh_b;
  real_T c2_uh_y;
  real_T c2_iy_x;
  real_T c2_jy_x;
  real_T c2_ky_x;
  real_T c2_ly_x;
  real_T c2_vh_a;
  real_T c2_vh_b;
  real_T c2_vh_y;
  real_T c2_my_x;
  real_T c2_ny_x;
  real_T c2_wh_a;
  real_T c2_wh_b;
  real_T c2_wh_y;
  real_T c2_xh_a;
  real_T c2_xh_b;
  real_T c2_xh_y;
  real_T c2_yh_a;
  real_T c2_yh_b;
  real_T c2_yh_y;
  real_T c2_ai_a;
  real_T c2_ai_b;
  real_T c2_ai_y;
  real_T c2_oy_x;
  real_T c2_py_x;
  real_T c2_qy_x;
  real_T c2_ry_x;
  real_T c2_sy_x;
  real_T c2_ty_x;
  real_T c2_uy_x;
  real_T c2_vy_x;
  real_T c2_bi_a;
  real_T c2_bi_b;
  real_T c2_bi_y;
  real_T c2_wy_x;
  real_T c2_xy_x;
  real_T c2_ci_a;
  real_T c2_ci_b;
  real_T c2_ci_y;
  real_T c2_yy_x;
  real_T c2_aab_x;
  real_T c2_bab_x;
  real_T c2_cab_x;
  real_T c2_di_a;
  real_T c2_di_b;
  real_T c2_di_y;
  real_T c2_dab_x;
  real_T c2_eab_x;
  real_T c2_ei_a;
  real_T c2_ei_b;
  real_T c2_ei_y;
  real_T c2_fi_a;
  real_T c2_fi_b;
  real_T c2_fi_y;
  real_T c2_fab_x;
  real_T c2_gab_x;
  real_T c2_hab_x;
  real_T c2_iab_x;
  real_T c2_jab_x;
  real_T c2_kab_x;
  real_T c2_gi_a;
  real_T c2_gi_b;
  real_T c2_gi_y;
  real_T c2_lab_x;
  real_T c2_mab_x;
  real_T c2_hi_a;
  real_T c2_hi_b;
  real_T c2_hi_y;
  real_T c2_nab_x;
  real_T c2_oab_x;
  real_T c2_pab_x;
  real_T c2_qab_x;
  real_T c2_ii_a;
  real_T c2_ii_b;
  real_T c2_ii_y;
  real_T c2_rab_x;
  real_T c2_sab_x;
  real_T c2_ji_a;
  real_T c2_ji_b;
  real_T c2_ji_y;
  real_T c2_ki_a;
  real_T c2_ki_b;
  real_T c2_ki_y;
  real_T c2_li_a;
  real_T c2_li_b;
  real_T c2_li_y;
  real_T c2_tab_x;
  real_T c2_uab_x;
  real_T c2_vab_x;
  real_T c2_wab_x;
  real_T c2_mi_a;
  real_T c2_mi_b;
  real_T c2_mi_y;
  real_T c2_xab_x;
  real_T c2_yab_x;
  real_T c2_abb_x;
  real_T c2_bbb_x;
  real_T c2_cbb_x;
  real_T c2_dbb_x;
  real_T c2_ebb_x;
  real_T c2_fbb_x;
  real_T c2_ni_a;
  real_T c2_ni_b;
  real_T c2_ni_y;
  real_T c2_gbb_x;
  real_T c2_hbb_x;
  real_T c2_oi_a;
  real_T c2_oi_b;
  real_T c2_oi_y;
  real_T c2_ibb_x;
  real_T c2_jbb_x;
  real_T c2_kbb_x;
  real_T c2_lbb_x;
  real_T c2_pi_a;
  real_T c2_pi_b;
  real_T c2_pi_y;
  real_T c2_mbb_x;
  real_T c2_nbb_x;
  real_T c2_qi_a;
  real_T c2_qi_b;
  real_T c2_qi_y;
  real_T c2_ri_a;
  real_T c2_ri_b;
  real_T c2_ri_y;
  real_T c2_obb_x;
  real_T c2_pbb_x;
  real_T c2_qbb_x;
  real_T c2_rbb_x;
  real_T c2_sbb_x;
  real_T c2_tbb_x;
  real_T c2_si_a;
  real_T c2_si_b;
  real_T c2_si_y;
  real_T c2_ubb_x;
  real_T c2_vbb_x;
  real_T c2_ti_a;
  real_T c2_ti_b;
  real_T c2_ti_y;
  real_T c2_wbb_x;
  real_T c2_xbb_x;
  real_T c2_ybb_x;
  real_T c2_acb_x;
  real_T c2_ui_a;
  real_T c2_ui_b;
  real_T c2_ui_y;
  real_T c2_bcb_x;
  real_T c2_ccb_x;
  real_T c2_vi_a;
  real_T c2_vi_b;
  real_T c2_vi_y;
  real_T c2_wi_a;
  real_T c2_wi_b;
  real_T c2_wi_y;
  real_T c2_xi_a;
  real_T c2_xi_b;
  real_T c2_xi_y;
  real_T c2_dcb_x;
  real_T c2_ecb_x;
  real_T c2_fcb_x;
  real_T c2_gcb_x;
  real_T c2_hcb_x;
  real_T c2_icb_x;
  real_T c2_yi_a;
  real_T c2_yi_b;
  real_T c2_yi_y;
  real_T c2_jcb_x;
  real_T c2_kcb_x;
  real_T c2_lcb_x;
  real_T c2_mcb_x;
  real_T c2_ncb_x;
  real_T c2_ocb_x;
  real_T c2_pcb_x;
  real_T c2_qcb_x;
  real_T c2_aj_a;
  real_T c2_aj_b;
  real_T c2_aj_y;
  real_T c2_rcb_x;
  real_T c2_scb_x;
  real_T c2_bj_a;
  real_T c2_bj_b;
  real_T c2_bj_y;
  real_T c2_tcb_x;
  real_T c2_ucb_x;
  real_T c2_vcb_x;
  real_T c2_wcb_x;
  real_T c2_cj_a;
  real_T c2_cj_b;
  real_T c2_cj_y;
  real_T c2_xcb_x;
  real_T c2_ycb_x;
  real_T c2_dj_a;
  real_T c2_dj_b;
  real_T c2_dj_y;
  real_T c2_ej_a;
  real_T c2_ej_b;
  real_T c2_ej_y;
  real_T c2_adb_x;
  real_T c2_bdb_x;
  real_T c2_cdb_x;
  real_T c2_ddb_x;
  real_T c2_edb_x;
  real_T c2_fdb_x;
  real_T c2_fj_a;
  real_T c2_fj_b;
  real_T c2_fj_y;
  real_T c2_gdb_x;
  real_T c2_hdb_x;
  real_T c2_gj_a;
  real_T c2_gj_b;
  real_T c2_gj_y;
  real_T c2_idb_x;
  real_T c2_jdb_x;
  real_T c2_kdb_x;
  real_T c2_ldb_x;
  real_T c2_hj_a;
  real_T c2_hj_b;
  real_T c2_hj_y;
  real_T c2_mdb_x;
  real_T c2_ndb_x;
  real_T c2_ij_a;
  real_T c2_ij_b;
  real_T c2_ij_y;
  real_T c2_jj_a;
  real_T c2_jj_b;
  real_T c2_jj_y;
  real_T c2_kj_a;
  real_T c2_kj_b;
  real_T c2_kj_y;
  real_T c2_lj_a;
  real_T c2_lj_b;
  real_T c2_lj_y;
  real_T c2_odb_x;
  real_T c2_pdb_x;
  real_T c2_qdb_x;
  real_T c2_rdb_x;
  real_T c2_sdb_x;
  real_T c2_tdb_x;
  real_T c2_udb_x;
  real_T c2_vdb_x;
  real_T c2_mj_a;
  real_T c2_mj_b;
  real_T c2_mj_y;
  real_T c2_wdb_x;
  real_T c2_xdb_x;
  real_T c2_nj_a;
  real_T c2_nj_b;
  real_T c2_nj_y;
  real_T c2_ydb_x;
  real_T c2_aeb_x;
  real_T c2_beb_x;
  real_T c2_ceb_x;
  real_T c2_oj_a;
  real_T c2_oj_b;
  real_T c2_oj_y;
  real_T c2_deb_x;
  real_T c2_eeb_x;
  real_T c2_pj_a;
  real_T c2_pj_b;
  real_T c2_pj_y;
  real_T c2_qj_a;
  real_T c2_qj_b;
  real_T c2_qj_y;
  real_T c2_feb_x;
  real_T c2_geb_x;
  real_T c2_heb_x;
  real_T c2_ieb_x;
  real_T c2_jeb_x;
  real_T c2_keb_x;
  real_T c2_rj_a;
  real_T c2_rj_b;
  real_T c2_rj_y;
  real_T c2_leb_x;
  real_T c2_meb_x;
  real_T c2_sj_a;
  real_T c2_sj_b;
  real_T c2_sj_y;
  real_T c2_neb_x;
  real_T c2_oeb_x;
  real_T c2_peb_x;
  real_T c2_qeb_x;
  real_T c2_tj_a;
  real_T c2_tj_b;
  real_T c2_tj_y;
  real_T c2_reb_x;
  real_T c2_seb_x;
  real_T c2_uj_a;
  real_T c2_uj_b;
  real_T c2_uj_y;
  real_T c2_vj_a;
  real_T c2_vj_b;
  real_T c2_vj_y;
  real_T c2_wj_a;
  real_T c2_wj_b;
  real_T c2_wj_y;
  real_T c2_teb_x;
  real_T c2_ueb_x;
  real_T c2_veb_x;
  real_T c2_web_x;
  real_T c2_xeb_x;
  real_T c2_yeb_x;
  real_T c2_xj_a;
  real_T c2_xj_b;
  real_T c2_xj_y;
  real_T c2_afb_x;
  real_T c2_bfb_x;
  real_T c2_cfb_x;
  real_T c2_dfb_x;
  real_T c2_efb_x;
  real_T c2_ffb_x;
  real_T c2_gfb_x;
  real_T c2_hfb_x;
  real_T c2_yj_a;
  real_T c2_yj_b;
  real_T c2_yj_y;
  real_T c2_ifb_x;
  real_T c2_jfb_x;
  real_T c2_ak_a;
  real_T c2_ak_b;
  real_T c2_ak_y;
  real_T c2_kfb_x;
  real_T c2_lfb_x;
  real_T c2_mfb_x;
  real_T c2_nfb_x;
  real_T c2_bk_a;
  real_T c2_bk_b;
  real_T c2_bk_y;
  real_T c2_ofb_x;
  real_T c2_pfb_x;
  real_T c2_ck_a;
  real_T c2_ck_b;
  real_T c2_ck_y;
  real_T c2_dk_a;
  real_T c2_dk_b;
  real_T c2_dk_y;
  real_T c2_qfb_x;
  real_T c2_rfb_x;
  real_T c2_sfb_x;
  real_T c2_tfb_x;
  real_T c2_ufb_x;
  real_T c2_vfb_x;
  real_T c2_ek_a;
  real_T c2_ek_b;
  real_T c2_ek_y;
  real_T c2_wfb_x;
  real_T c2_xfb_x;
  real_T c2_fk_a;
  real_T c2_fk_b;
  real_T c2_fk_y;
  real_T c2_yfb_x;
  real_T c2_agb_x;
  real_T c2_bgb_x;
  real_T c2_cgb_x;
  real_T c2_gk_a;
  real_T c2_gk_b;
  real_T c2_gk_y;
  real_T c2_dgb_x;
  real_T c2_egb_x;
  real_T c2_hk_a;
  real_T c2_hk_b;
  real_T c2_hk_y;
  real_T c2_ik_a;
  real_T c2_ik_b;
  real_T c2_ik_y;
  real_T c2_jk_a;
  real_T c2_jk_b;
  real_T c2_jk_y;
  real_T c2_kk_a;
  real_T c2_kk_b;
  real_T c2_kk_y;
  real_T c2_fgb_x;
  real_T c2_ggb_x;
  real_T c2_hgb_x;
  real_T c2_igb_x;
  real_T c2_jgb_x;
  real_T c2_kgb_x;
  real_T c2_lgb_x;
  real_T c2_mgb_x;
  real_T c2_lk_a;
  real_T c2_lk_b;
  real_T c2_lk_y;
  real_T c2_ngb_x;
  real_T c2_ogb_x;
  real_T c2_mk_a;
  real_T c2_mk_b;
  real_T c2_mk_y;
  real_T c2_pgb_x;
  real_T c2_qgb_x;
  real_T c2_rgb_x;
  real_T c2_sgb_x;
  real_T c2_nk_a;
  real_T c2_nk_b;
  real_T c2_nk_y;
  real_T c2_tgb_x;
  real_T c2_ugb_x;
  real_T c2_ok_a;
  real_T c2_ok_b;
  real_T c2_ok_y;
  real_T c2_pk_a;
  real_T c2_pk_b;
  real_T c2_pk_y;
  real_T c2_vgb_x;
  real_T c2_wgb_x;
  real_T c2_xgb_x;
  real_T c2_ygb_x;
  real_T c2_ahb_x;
  real_T c2_bhb_x;
  real_T c2_qk_a;
  real_T c2_qk_b;
  real_T c2_qk_y;
  real_T c2_chb_x;
  real_T c2_dhb_x;
  real_T c2_rk_a;
  real_T c2_rk_b;
  real_T c2_rk_y;
  real_T c2_ehb_x;
  real_T c2_fhb_x;
  real_T c2_ghb_x;
  real_T c2_hhb_x;
  real_T c2_sk_a;
  real_T c2_sk_b;
  real_T c2_sk_y;
  real_T c2_ihb_x;
  real_T c2_jhb_x;
  real_T c2_tk_a;
  real_T c2_tk_b;
  real_T c2_tk_y;
  real_T c2_uk_a;
  real_T c2_uk_b;
  real_T c2_uk_y;
  real_T c2_vk_a;
  real_T c2_vk_b;
  real_T c2_vk_y;
  real_T c2_khb_x;
  real_T c2_lhb_x;
  real_T c2_mhb_x;
  real_T c2_nhb_x;
  real_T c2_ohb_x;
  real_T c2_phb_x;
  real_T c2_qhb_x;
  real_T c2_rhb_x;
  real_T c2_wk_a;
  real_T c2_wk_b;
  real_T c2_wk_y;
  real_T c2_shb_x;
  real_T c2_thb_x;
  real_T c2_xk_a;
  real_T c2_xk_b;
  real_T c2_xk_y;
  real_T c2_uhb_x;
  real_T c2_vhb_x;
  real_T c2_whb_x;
  real_T c2_xhb_x;
  real_T c2_yk_a;
  real_T c2_yk_b;
  real_T c2_yk_y;
  real_T c2_yhb_x;
  real_T c2_aib_x;
  real_T c2_al_a;
  real_T c2_al_b;
  real_T c2_al_y;
  real_T c2_bl_a;
  real_T c2_bl_b;
  real_T c2_bl_y;
  real_T c2_bib_x;
  real_T c2_cib_x;
  real_T c2_dib_x;
  real_T c2_eib_x;
  real_T c2_fib_x;
  real_T c2_gib_x;
  real_T c2_cl_a;
  real_T c2_cl_b;
  real_T c2_cl_y;
  real_T c2_hib_x;
  real_T c2_iib_x;
  real_T c2_dl_a;
  real_T c2_dl_b;
  real_T c2_dl_y;
  real_T c2_jib_x;
  real_T c2_kib_x;
  real_T c2_lib_x;
  real_T c2_mib_x;
  real_T c2_el_a;
  real_T c2_el_b;
  real_T c2_el_y;
  real_T c2_nib_x;
  real_T c2_oib_x;
  real_T c2_fl_a;
  real_T c2_fl_b;
  real_T c2_fl_y;
  real_T c2_gl_a;
  real_T c2_gl_b;
  real_T c2_gl_y;
  real_T c2_hl_a;
  real_T c2_hl_b;
  real_T c2_hl_y;
  real_T c2_pib_x;
  real_T c2_qib_x;
  real_T c2_rib_x;
  real_T c2_sib_x;
  real_T c2_il_a;
  real_T c2_il_b;
  real_T c2_il_y;
  real_T c2_tib_x;
  real_T c2_uib_x;
  real_T c2_vib_x;
  real_T c2_wib_x;
  real_T c2_xib_x;
  real_T c2_yib_x;
  real_T c2_ajb_x;
  real_T c2_bjb_x;
  real_T c2_jl_a;
  real_T c2_jl_b;
  real_T c2_jl_y;
  real_T c2_cjb_x;
  real_T c2_djb_x;
  real_T c2_ejb_x;
  real_T c2_fjb_x;
  real_T c2_kl_a;
  real_T c2_kl_b;
  real_T c2_kl_y;
  real_T c2_ll_a;
  real_T c2_ll_b;
  real_T c2_ll_y;
  real_T c2_gjb_x;
  real_T c2_hjb_x;
  real_T c2_ijb_x;
  real_T c2_jjb_x;
  real_T c2_kjb_x;
  real_T c2_ljb_x;
  real_T c2_ml_a;
  real_T c2_ml_b;
  real_T c2_ml_y;
  real_T c2_mjb_x;
  real_T c2_njb_x;
  real_T c2_ojb_x;
  real_T c2_pjb_x;
  real_T c2_nl_a;
  real_T c2_nl_b;
  real_T c2_nl_y;
  real_T c2_ol_a;
  real_T c2_ol_b;
  real_T c2_ol_y;
  real_T c2_pl_a;
  real_T c2_pl_b;
  real_T c2_pl_y;
  real_T c2_qjb_x;
  real_T c2_rjb_x;
  real_T c2_sjb_x;
  real_T c2_tjb_x;
  real_T c2_ql_a;
  real_T c2_ql_b;
  real_T c2_ql_y;
  real_T c2_ujb_x;
  real_T c2_vjb_x;
  real_T c2_wjb_x;
  real_T c2_xjb_x;
  real_T c2_yjb_x;
  real_T c2_akb_x;
  real_T c2_rl_a;
  real_T c2_rl_b;
  real_T c2_rl_y;
  real_T c2_bkb_x;
  real_T c2_ckb_x;
  real_T c2_dkb_x;
  real_T c2_ekb_x;
  real_T c2_sl_a;
  real_T c2_sl_b;
  real_T c2_sl_y;
  real_T c2_tl_a;
  real_T c2_tl_b;
  real_T c2_tl_y;
  real_T c2_fkb_x;
  real_T c2_gkb_x;
  real_T c2_hkb_x;
  real_T c2_ikb_x;
  real_T c2_jkb_x;
  real_T c2_kkb_x;
  real_T c2_ul_a;
  real_T c2_ul_b;
  real_T c2_ul_y;
  real_T c2_lkb_x;
  real_T c2_mkb_x;
  real_T c2_nkb_x;
  real_T c2_okb_x;
  real_T c2_vl_a;
  real_T c2_vl_b;
  real_T c2_vl_y;
  real_T c2_wl_a;
  real_T c2_wl_b;
  real_T c2_wl_y;
  real_T c2_xl_a;
  real_T c2_xl_b;
  real_T c2_xl_y;
  real_T c2_pkb_x;
  real_T c2_qkb_x;
  real_T c2_rkb_x;
  real_T c2_skb_x;
  real_T c2_tkb_x;
  real_T c2_ukb_x;
  real_T c2_vkb_x;
  real_T c2_wkb_x;
  real_T c2_yl_a;
  real_T c2_yl_b;
  real_T c2_yl_y;
  real_T c2_xkb_x;
  real_T c2_ykb_x;
  real_T c2_alb_x;
  real_T c2_blb_x;
  real_T c2_am_a;
  real_T c2_am_b;
  real_T c2_am_y;
  real_T c2_bm_a;
  real_T c2_bm_b;
  real_T c2_bm_y;
  real_T c2_clb_x;
  real_T c2_dlb_x;
  real_T c2_elb_x;
  real_T c2_flb_x;
  real_T c2_glb_x;
  real_T c2_hlb_x;
  real_T c2_cm_a;
  real_T c2_cm_b;
  real_T c2_cm_y;
  real_T c2_ilb_x;
  real_T c2_jlb_x;
  real_T c2_klb_x;
  real_T c2_llb_x;
  real_T c2_dm_a;
  real_T c2_dm_b;
  real_T c2_dm_y;
  real_T c2_em_a;
  real_T c2_em_b;
  real_T c2_em_y;
  real_T c2_fm_a;
  real_T c2_fm_b;
  real_T c2_fm_y;
  real_T c2_mlb_x;
  real_T c2_nlb_x;
  real_T c2_olb_x;
  real_T c2_plb_x;
  real_T c2_gm_a;
  real_T c2_gm_b;
  real_T c2_gm_y;
  real_T c2_qlb_x;
  real_T c2_rlb_x;
  real_T c2_slb_x;
  real_T c2_tlb_x;
  real_T c2_ulb_x;
  real_T c2_vlb_x;
  real_T c2_hm_a;
  real_T c2_hm_b;
  real_T c2_hm_y;
  real_T c2_wlb_x;
  real_T c2_xlb_x;
  real_T c2_ylb_x;
  real_T c2_amb_x;
  real_T c2_im_a;
  real_T c2_im_b;
  real_T c2_im_y;
  real_T c2_jm_a;
  real_T c2_jm_b;
  real_T c2_jm_y;
  real_T c2_bmb_x;
  real_T c2_cmb_x;
  real_T c2_dmb_x;
  real_T c2_emb_x;
  real_T c2_fmb_x;
  real_T c2_gmb_x;
  real_T c2_km_a;
  real_T c2_km_b;
  real_T c2_km_y;
  real_T c2_hmb_x;
  real_T c2_imb_x;
  real_T c2_jmb_x;
  real_T c2_kmb_x;
  real_T c2_lm_a;
  real_T c2_lm_b;
  real_T c2_lm_y;
  real_T c2_mm_a;
  real_T c2_mm_b;
  real_T c2_mm_y;
  real_T c2_nm_a;
  real_T c2_nm_b;
  real_T c2_nm_y;
  real_T c2_lmb_x;
  real_T c2_mmb_x;
  real_T c2_nmb_x;
  real_T c2_omb_x;
  real_T c2_pmb_x;
  real_T c2_qmb_x;
  real_T c2_rmb_x;
  real_T c2_smb_x;
  real_T c2_om_a;
  real_T c2_om_b;
  real_T c2_om_y;
  real_T c2_tmb_x;
  real_T c2_umb_x;
  real_T c2_vmb_x;
  real_T c2_wmb_x;
  real_T c2_pm_a;
  real_T c2_pm_b;
  real_T c2_pm_y;
  real_T c2_qm_a;
  real_T c2_qm_b;
  real_T c2_qm_y;
  real_T c2_xmb_x;
  real_T c2_ymb_x;
  real_T c2_anb_x;
  real_T c2_bnb_x;
  real_T c2_cnb_x;
  real_T c2_dnb_x;
  real_T c2_rm_a;
  real_T c2_rm_b;
  real_T c2_rm_y;
  real_T c2_enb_x;
  real_T c2_fnb_x;
  real_T c2_gnb_x;
  real_T c2_hnb_x;
  real_T c2_sm_a;
  real_T c2_sm_b;
  real_T c2_sm_y;
  real_T c2_tm_a;
  real_T c2_tm_b;
  real_T c2_tm_y;
  real_T c2_um_a;
  real_T c2_um_b;
  real_T c2_um_y;
  int32_T c2_i28;
  static real_T c2_dv13[3] = { 0.0, 0.0, 0.0892 };

  real_T c2_inb_x;
  real_T c2_jnb_x;
  real_T c2_vm_b;
  real_T c2_vm_y;
  real_T c2_knb_x;
  real_T c2_lnb_x;
  real_T c2_vm_a;
  real_T c2_wm_b;
  real_T c2_wm_y;
  real_T c2_A;
  real_T c2_mnb_x;
  real_T c2_nnb_x;
  real_T c2_xm_y;
  real_T c2_onb_x;
  real_T c2_pnb_x;
  real_T c2_xm_b;
  real_T c2_ym_y;
  real_T c2_qnb_x;
  real_T c2_rnb_x;
  real_T c2_wm_a;
  real_T c2_ym_b;
  real_T c2_an_y;
  real_T c2_b_A;
  real_T c2_snb_x;
  real_T c2_tnb_x;
  real_T c2_bn_y;
  real_T c2_unb_x;
  real_T c2_vnb_x;
  real_T c2_an_b;
  real_T c2_cn_y;
  real_T c2_c_A;
  real_T c2_wnb_x;
  real_T c2_xnb_x;
  real_T c2_dn_y;
  real_T c2_ynb_x;
  real_T c2_aob_x;
  real_T c2_bn_b;
  real_T c2_en_y;
  real_T c2_bob_x;
  real_T c2_cob_x;
  real_T c2_xm_a;
  real_T c2_cn_b;
  real_T c2_fn_y;
  real_T c2_dob_x;
  real_T c2_eob_x;
  real_T c2_ym_a;
  real_T c2_dn_b;
  real_T c2_gn_y;
  real_T c2_d_A;
  real_T c2_fob_x;
  real_T c2_gob_x;
  real_T c2_hn_y;
  real_T c2_hob_x;
  real_T c2_iob_x;
  real_T c2_en_b;
  real_T c2_in_y;
  real_T c2_job_x;
  real_T c2_kob_x;
  real_T c2_an_a;
  real_T c2_fn_b;
  real_T c2_jn_y;
  real_T c2_e_A;
  real_T c2_lob_x;
  real_T c2_mob_x;
  real_T c2_kn_y;
  real_T c2_nob_x;
  real_T c2_oob_x;
  real_T c2_gn_b;
  real_T c2_ln_y;
  real_T c2_pob_x;
  real_T c2_qob_x;
  real_T c2_bn_a;
  real_T c2_hn_b;
  real_T c2_mn_y;
  real_T c2_rob_x;
  real_T c2_sob_x;
  real_T c2_cn_a;
  real_T c2_in_b;
  real_T c2_nn_y;
  real_T c2_f_A;
  real_T c2_tob_x;
  real_T c2_uob_x;
  real_T c2_on_y;
  real_T c2_vob_x;
  real_T c2_wob_x;
  real_T c2_jn_b;
  real_T c2_pn_y;
  real_T c2_xob_x;
  real_T c2_yob_x;
  real_T c2_dn_a;
  real_T c2_kn_b;
  real_T c2_qn_y;
  real_T c2_apb_x;
  real_T c2_bpb_x;
  real_T c2_en_a;
  real_T c2_ln_b;
  real_T c2_rn_y;
  real_T c2_g_A;
  real_T c2_cpb_x;
  real_T c2_dpb_x;
  real_T c2_sn_y;
  real_T c2_epb_x;
  real_T c2_fpb_x;
  real_T c2_mn_b;
  real_T c2_tn_y;
  real_T c2_gpb_x;
  real_T c2_hpb_x;
  real_T c2_fn_a;
  real_T c2_nn_b;
  real_T c2_un_y;
  real_T c2_h_A;
  real_T c2_ipb_x;
  real_T c2_jpb_x;
  real_T c2_vn_y;
  real_T c2_kpb_x;
  real_T c2_lpb_x;
  real_T c2_on_b;
  real_T c2_wn_y;
  real_T c2_mpb_x;
  real_T c2_npb_x;
  real_T c2_gn_a;
  real_T c2_pn_b;
  real_T c2_xn_y;
  real_T c2_opb_x;
  real_T c2_ppb_x;
  real_T c2_hn_a;
  real_T c2_qn_b;
  real_T c2_yn_y;
  real_T c2_i_A;
  real_T c2_qpb_x;
  real_T c2_rpb_x;
  real_T c2_ao_y;
  real_T c2_spb_x;
  real_T c2_tpb_x;
  real_T c2_rn_b;
  real_T c2_bo_y;
  real_T c2_upb_x;
  real_T c2_vpb_x;
  real_T c2_in_a;
  real_T c2_sn_b;
  real_T c2_co_y;
  real_T c2_j_A;
  real_T c2_wpb_x;
  real_T c2_xpb_x;
  real_T c2_do_y;
  real_T c2_ypb_x;
  real_T c2_aqb_x;
  real_T c2_tn_b;
  real_T c2_eo_y;
  real_T c2_bqb_x;
  real_T c2_cqb_x;
  real_T c2_jn_a;
  real_T c2_un_b;
  real_T c2_fo_y;
  real_T c2_k_A;
  real_T c2_dqb_x;
  real_T c2_eqb_x;
  real_T c2_go_y;
  real_T c2_fqb_x;
  real_T c2_gqb_x;
  real_T c2_vn_b;
  real_T c2_ho_y;
  real_T c2_l_A;
  real_T c2_hqb_x;
  real_T c2_iqb_x;
  real_T c2_io_y;
  real_T c2_jqb_x;
  real_T c2_kqb_x;
  real_T c2_wn_b;
  real_T c2_jo_y;
  real_T c2_m_A;
  real_T c2_lqb_x;
  real_T c2_mqb_x;
  real_T c2_ko_y;
  real_T c2_nqb_x;
  real_T c2_oqb_x;
  real_T c2_xn_b;
  real_T c2_lo_y;
  real_T c2_pqb_x;
  real_T c2_qqb_x;
  real_T c2_kn_a;
  real_T c2_yn_b;
  real_T c2_mo_y;
  real_T c2_n_A;
  real_T c2_rqb_x;
  real_T c2_sqb_x;
  real_T c2_no_y;
  real_T c2_tqb_x;
  real_T c2_uqb_x;
  real_T c2_ao_b;
  real_T c2_oo_y;
  real_T c2_vqb_x;
  real_T c2_wqb_x;
  real_T c2_ln_a;
  real_T c2_bo_b;
  real_T c2_po_y;
  real_T c2_xqb_x;
  real_T c2_yqb_x;
  real_T c2_mn_a;
  real_T c2_co_b;
  real_T c2_qo_y;
  real_T c2_o_A;
  real_T c2_arb_x;
  real_T c2_brb_x;
  real_T c2_ro_y;
  real_T c2_crb_x;
  real_T c2_drb_x;
  real_T c2_do_b;
  real_T c2_so_y;
  real_T c2_erb_x;
  real_T c2_frb_x;
  real_T c2_nn_a;
  real_T c2_eo_b;
  real_T c2_to_y;
  real_T c2_grb_x;
  real_T c2_hrb_x;
  real_T c2_on_a;
  real_T c2_fo_b;
  real_T c2_uo_y;
  real_T c2_p_A;
  real_T c2_irb_x;
  real_T c2_jrb_x;
  real_T c2_vo_y;
  real_T c2_krb_x;
  real_T c2_lrb_x;
  real_T c2_go_b;
  real_T c2_wo_y;
  real_T c2_mrb_x;
  real_T c2_nrb_x;
  real_T c2_pn_a;
  real_T c2_ho_b;
  real_T c2_xo_y;
  real_T c2_orb_x;
  real_T c2_prb_x;
  real_T c2_qn_a;
  real_T c2_io_b;
  real_T c2_yo_y;
  real_T c2_q_A;
  real_T c2_qrb_x;
  real_T c2_rrb_x;
  real_T c2_ap_y;
  real_T c2_srb_x;
  real_T c2_trb_x;
  real_T c2_jo_b;
  real_T c2_bp_y;
  real_T c2_urb_x;
  real_T c2_vrb_x;
  real_T c2_rn_a;
  real_T c2_ko_b;
  real_T c2_cp_y;
  real_T c2_r_A;
  real_T c2_wrb_x;
  real_T c2_xrb_x;
  real_T c2_dp_y;
  real_T c2_yrb_x;
  real_T c2_asb_x;
  real_T c2_lo_b;
  real_T c2_ep_y;
  real_T c2_s_A;
  real_T c2_bsb_x;
  real_T c2_csb_x;
  real_T c2_fp_y;
  real_T c2_dsb_x;
  real_T c2_esb_x;
  real_T c2_mo_b;
  real_T c2_gp_y;
  real_T c2_fsb_x;
  real_T c2_gsb_x;
  real_T c2_sn_a;
  real_T c2_no_b;
  real_T c2_hp_y;
  real_T c2_hsb_x;
  real_T c2_isb_x;
  real_T c2_tn_a;
  real_T c2_oo_b;
  real_T c2_ip_y;
  real_T c2_t_A;
  real_T c2_jsb_x;
  real_T c2_ksb_x;
  real_T c2_jp_y;
  real_T c2_lsb_x;
  real_T c2_msb_x;
  real_T c2_po_b;
  real_T c2_kp_y;
  real_T c2_nsb_x;
  real_T c2_osb_x;
  real_T c2_un_a;
  real_T c2_qo_b;
  real_T c2_lp_y;
  real_T c2_u_A;
  real_T c2_psb_x;
  real_T c2_qsb_x;
  real_T c2_mp_y;
  real_T c2_rsb_x;
  real_T c2_ssb_x;
  real_T c2_ro_b;
  real_T c2_np_y;
  real_T c2_tsb_x;
  real_T c2_usb_x;
  real_T c2_vn_a;
  real_T c2_so_b;
  real_T c2_op_y;
  real_T c2_v_A;
  real_T c2_vsb_x;
  real_T c2_wsb_x;
  real_T c2_pp_y;
  real_T c2_xsb_x;
  real_T c2_ysb_x;
  real_T c2_to_b;
  real_T c2_qp_y;
  real_T c2_w_A;
  real_T c2_atb_x;
  real_T c2_btb_x;
  real_T c2_rp_y;
  real_T c2_ctb_x;
  real_T c2_dtb_x;
  real_T c2_uo_b;
  real_T c2_sp_y;
  real_T c2_x_A;
  real_T c2_etb_x;
  real_T c2_ftb_x;
  real_T c2_tp_y;
  real_T c2_gtb_x;
  real_T c2_htb_x;
  real_T c2_vo_b;
  real_T c2_up_y;
  real_T c2_itb_x;
  real_T c2_jtb_x;
  real_T c2_wn_a;
  real_T c2_wo_b;
  real_T c2_vp_y;
  real_T c2_y_A;
  real_T c2_ktb_x;
  real_T c2_ltb_x;
  real_T c2_wp_y;
  real_T c2_mtb_x;
  real_T c2_ntb_x;
  real_T c2_xo_b;
  real_T c2_xp_y;
  real_T c2_otb_x;
  real_T c2_ptb_x;
  real_T c2_qtb_x;
  real_T c2_rtb_x;
  real_T c2_xn_a;
  real_T c2_yo_b;
  real_T c2_yp_y;
  real_T c2_stb_x;
  real_T c2_ttb_x;
  real_T c2_yn_a;
  real_T c2_ap_b;
  real_T c2_aq_y;
  real_T c2_utb_x;
  real_T c2_vtb_x;
  real_T c2_wtb_x;
  real_T c2_xtb_x;
  real_T c2_ao_a;
  real_T c2_bp_b;
  real_T c2_bq_y;
  real_T c2_ytb_x;
  real_T c2_aub_x;
  real_T c2_bo_a;
  real_T c2_cp_b;
  real_T c2_cq_y;
  real_T c2_co_a;
  real_T c2_dp_b;
  real_T c2_dq_y;
  real_T c2_ab_A;
  real_T c2_bub_x;
  real_T c2_cub_x;
  real_T c2_eq_y;
  real_T c2_dub_x;
  real_T c2_eub_x;
  real_T c2_ep_b;
  real_T c2_fq_y;
  real_T c2_fub_x;
  real_T c2_gub_x;
  real_T c2_hub_x;
  real_T c2_iub_x;
  real_T c2_do_a;
  real_T c2_fp_b;
  real_T c2_gq_y;
  real_T c2_jub_x;
  real_T c2_kub_x;
  real_T c2_eo_a;
  real_T c2_gp_b;
  real_T c2_hq_y;
  real_T c2_lub_x;
  real_T c2_mub_x;
  real_T c2_nub_x;
  real_T c2_oub_x;
  real_T c2_fo_a;
  real_T c2_hp_b;
  real_T c2_iq_y;
  real_T c2_pub_x;
  real_T c2_qub_x;
  real_T c2_go_a;
  real_T c2_ip_b;
  real_T c2_jq_y;
  real_T c2_ho_a;
  real_T c2_jp_b;
  real_T c2_kq_y;
  real_T c2_bb_A;
  real_T c2_rub_x;
  real_T c2_sub_x;
  real_T c2_lq_y;
  real_T c2_tub_x;
  real_T c2_uub_x;
  real_T c2_kp_b;
  real_T c2_mq_y;
  real_T c2_vub_x;
  real_T c2_wub_x;
  real_T c2_io_a;
  real_T c2_lp_b;
  real_T c2_nq_y;
  real_T c2_xub_x;
  real_T c2_yub_x;
  real_T c2_jo_a;
  real_T c2_mp_b;
  real_T c2_oq_y;
  real_T c2_cb_A;
  real_T c2_avb_x;
  real_T c2_bvb_x;
  real_T c2_pq_y;
  real_T c2_cvb_x;
  real_T c2_dvb_x;
  real_T c2_np_b;
  real_T c2_qq_y;
  real_T c2_evb_x;
  real_T c2_fvb_x;
  real_T c2_ko_a;
  real_T c2_op_b;
  real_T c2_rq_y;
  real_T c2_gvb_x;
  real_T c2_hvb_x;
  real_T c2_lo_a;
  real_T c2_pp_b;
  real_T c2_sq_y;
  real_T c2_db_A;
  real_T c2_ivb_x;
  real_T c2_jvb_x;
  real_T c2_tq_y;
  real_T c2_kvb_x;
  real_T c2_lvb_x;
  real_T c2_qp_b;
  real_T c2_uq_y;
  real_T c2_mvb_x;
  real_T c2_nvb_x;
  real_T c2_ovb_x;
  real_T c2_pvb_x;
  real_T c2_mo_a;
  real_T c2_rp_b;
  real_T c2_vq_y;
  real_T c2_qvb_x;
  real_T c2_rvb_x;
  real_T c2_no_a;
  real_T c2_sp_b;
  real_T c2_wq_y;
  real_T c2_svb_x;
  real_T c2_tvb_x;
  real_T c2_uvb_x;
  real_T c2_vvb_x;
  real_T c2_oo_a;
  real_T c2_tp_b;
  real_T c2_xq_y;
  real_T c2_wvb_x;
  real_T c2_xvb_x;
  real_T c2_po_a;
  real_T c2_up_b;
  real_T c2_yq_y;
  real_T c2_qo_a;
  real_T c2_vp_b;
  real_T c2_ar_y;
  real_T c2_eb_A;
  real_T c2_yvb_x;
  real_T c2_awb_x;
  real_T c2_br_y;
  real_T c2_bwb_x;
  real_T c2_cwb_x;
  real_T c2_wp_b;
  real_T c2_cr_y;
  real_T c2_dwb_x;
  real_T c2_ewb_x;
  real_T c2_ro_a;
  real_T c2_xp_b;
  real_T c2_dr_y;
  real_T c2_fb_A;
  real_T c2_fwb_x;
  real_T c2_gwb_x;
  real_T c2_er_y;
  real_T c2_hwb_x;
  real_T c2_iwb_x;
  real_T c2_yp_b;
  real_T c2_fr_y;
  real_T c2_gb_A;
  real_T c2_jwb_x;
  real_T c2_kwb_x;
  real_T c2_gr_y;
  real_T c2_lwb_x;
  real_T c2_mwb_x;
  real_T c2_aq_b;
  real_T c2_hr_y;
  real_T c2_nwb_x;
  real_T c2_owb_x;
  real_T c2_pwb_x;
  real_T c2_qwb_x;
  real_T c2_so_a;
  real_T c2_bq_b;
  real_T c2_ir_y;
  real_T c2_rwb_x;
  real_T c2_swb_x;
  real_T c2_to_a;
  real_T c2_cq_b;
  real_T c2_jr_y;
  real_T c2_twb_x;
  real_T c2_uwb_x;
  real_T c2_vwb_x;
  real_T c2_wwb_x;
  real_T c2_uo_a;
  real_T c2_dq_b;
  real_T c2_kr_y;
  real_T c2_xwb_x;
  real_T c2_ywb_x;
  real_T c2_vo_a;
  real_T c2_eq_b;
  real_T c2_lr_y;
  real_T c2_wo_a;
  real_T c2_fq_b;
  real_T c2_mr_y;
  real_T c2_hb_A;
  real_T c2_axb_x;
  real_T c2_bxb_x;
  real_T c2_nr_y;
  real_T c2_cxb_x;
  real_T c2_dxb_x;
  real_T c2_gq_b;
  real_T c2_or_y;
  real_T c2_exb_x;
  real_T c2_fxb_x;
  real_T c2_xo_a;
  real_T c2_hq_b;
  real_T c2_pr_y;
  real_T c2_gxb_x;
  real_T c2_hxb_x;
  real_T c2_yo_a;
  real_T c2_iq_b;
  real_T c2_qr_y;
  real_T c2_ib_A;
  real_T c2_ixb_x;
  real_T c2_jxb_x;
  real_T c2_rr_y;
  real_T c2_kxb_x;
  real_T c2_lxb_x;
  real_T c2_jq_b;
  real_T c2_sr_y;
  real_T c2_mxb_x;
  real_T c2_nxb_x;
  real_T c2_ap_a;
  real_T c2_kq_b;
  real_T c2_tr_y;
  real_T c2_oxb_x;
  real_T c2_pxb_x;
  real_T c2_bp_a;
  real_T c2_lq_b;
  real_T c2_ur_y;
  real_T c2_jb_A;
  real_T c2_qxb_x;
  real_T c2_rxb_x;
  real_T c2_vr_y;
  real_T c2_sxb_x;
  real_T c2_txb_x;
  real_T c2_mq_b;
  real_T c2_wr_y;
  real_T c2_uxb_x;
  real_T c2_vxb_x;
  real_T c2_wxb_x;
  real_T c2_xxb_x;
  real_T c2_cp_a;
  real_T c2_nq_b;
  real_T c2_xr_y;
  real_T c2_yxb_x;
  real_T c2_ayb_x;
  real_T c2_byb_x;
  real_T c2_cyb_x;
  real_T c2_dp_a;
  real_T c2_oq_b;
  real_T c2_yr_y;
  real_T c2_ep_a;
  real_T c2_pq_b;
  real_T c2_as_y;
  real_T c2_kb_A;
  real_T c2_dyb_x;
  real_T c2_eyb_x;
  real_T c2_bs_y;
  real_T c2_fyb_x;
  real_T c2_gyb_x;
  real_T c2_qq_b;
  real_T c2_cs_y;
  real_T c2_hyb_x;
  real_T c2_iyb_x;
  real_T c2_fp_a;
  real_T c2_rq_b;
  real_T c2_ds_y;
  real_T c2_lb_A;
  real_T c2_jyb_x;
  real_T c2_kyb_x;
  real_T c2_es_y;
  real_T c2_lyb_x;
  real_T c2_myb_x;
  real_T c2_sq_b;
  real_T c2_fs_y;
  real_T c2_nyb_x;
  real_T c2_oyb_x;
  real_T c2_gp_a;
  real_T c2_tq_b;
  real_T c2_gs_y;
  real_T c2_mb_A;
  real_T c2_pyb_x;
  real_T c2_qyb_x;
  real_T c2_hs_y;
  real_T c2_ryb_x;
  real_T c2_syb_x;
  real_T c2_uq_b;
  real_T c2_is_y;
  real_T c2_tyb_x;
  real_T c2_uyb_x;
  real_T c2_vyb_x;
  real_T c2_wyb_x;
  real_T c2_hp_a;
  real_T c2_vq_b;
  real_T c2_js_y;
  real_T c2_xyb_x;
  real_T c2_yyb_x;
  real_T c2_aac_x;
  real_T c2_bac_x;
  real_T c2_ip_a;
  real_T c2_wq_b;
  real_T c2_ks_y;
  real_T c2_jp_a;
  real_T c2_xq_b;
  real_T c2_ls_y;
  real_T c2_nb_A;
  real_T c2_cac_x;
  real_T c2_dac_x;
  real_T c2_ms_y;
  real_T c2_eac_x;
  real_T c2_fac_x;
  real_T c2_yq_b;
  real_T c2_ns_y;
  real_T c2_ob_A;
  real_T c2_gac_x;
  real_T c2_hac_x;
  real_T c2_os_y;
  real_T c2_iac_x;
  real_T c2_jac_x;
  real_T c2_ar_b;
  real_T c2_ps_y;
  real_T c2_pb_A;
  real_T c2_kac_x;
  real_T c2_lac_x;
  real_T c2_qs_y;
  real_T c2_mac_x;
  real_T c2_nac_x;
  real_T c2_br_b;
  real_T c2_rs_y;
  real_T c2_oac_x;
  real_T c2_pac_x;
  real_T c2_kp_a;
  real_T c2_cr_b;
  real_T c2_ss_y;
  real_T c2_qb_A;
  real_T c2_qac_x;
  real_T c2_rac_x;
  real_T c2_ts_y;
  real_T c2_sac_x;
  real_T c2_tac_x;
  real_T c2_dr_b;
  real_T c2_us_y;
  real_T c2_uac_x;
  real_T c2_vac_x;
  real_T c2_lp_a;
  real_T c2_er_b;
  real_T c2_vs_y;
  real_T c2_rb_A;
  real_T c2_wac_x;
  real_T c2_xac_x;
  real_T c2_ws_y;
  real_T c2_yac_x;
  real_T c2_abc_x;
  real_T c2_fr_b;
  real_T c2_xs_y;
  real_T c2_bbc_x;
  real_T c2_cbc_x;
  real_T c2_dbc_x;
  real_T c2_ebc_x;
  real_T c2_mp_a;
  real_T c2_gr_b;
  real_T c2_ys_y;
  real_T c2_fbc_x;
  real_T c2_gbc_x;
  real_T c2_np_a;
  real_T c2_hr_b;
  real_T c2_at_y;
  real_T c2_hbc_x;
  real_T c2_ibc_x;
  real_T c2_jbc_x;
  real_T c2_kbc_x;
  real_T c2_op_a;
  real_T c2_ir_b;
  real_T c2_bt_y;
  real_T c2_lbc_x;
  real_T c2_mbc_x;
  real_T c2_pp_a;
  real_T c2_jr_b;
  real_T c2_ct_y;
  real_T c2_qp_a;
  real_T c2_kr_b;
  real_T c2_dt_y;
  real_T c2_sb_A;
  real_T c2_nbc_x;
  real_T c2_obc_x;
  real_T c2_et_y;
  real_T c2_pbc_x;
  real_T c2_qbc_x;
  real_T c2_lr_b;
  real_T c2_ft_y;
  real_T c2_rbc_x;
  real_T c2_sbc_x;
  real_T c2_tbc_x;
  real_T c2_ubc_x;
  real_T c2_rp_a;
  real_T c2_mr_b;
  real_T c2_gt_y;
  real_T c2_vbc_x;
  real_T c2_wbc_x;
  real_T c2_sp_a;
  real_T c2_nr_b;
  real_T c2_ht_y;
  real_T c2_xbc_x;
  real_T c2_ybc_x;
  real_T c2_acc_x;
  real_T c2_bcc_x;
  real_T c2_tp_a;
  real_T c2_or_b;
  real_T c2_it_y;
  real_T c2_ccc_x;
  real_T c2_dcc_x;
  real_T c2_up_a;
  real_T c2_pr_b;
  real_T c2_jt_y;
  real_T c2_vp_a;
  real_T c2_qr_b;
  real_T c2_kt_y;
  real_T c2_tb_A;
  real_T c2_ecc_x;
  real_T c2_fcc_x;
  real_T c2_lt_y;
  real_T c2_gcc_x;
  real_T c2_hcc_x;
  real_T c2_rr_b;
  real_T c2_mt_y;
  real_T c2_icc_x;
  real_T c2_jcc_x;
  real_T c2_kcc_x;
  real_T c2_lcc_x;
  real_T c2_mcc_x;
  real_T c2_ncc_x;
  real_T c2_wp_a;
  real_T c2_sr_b;
  real_T c2_nt_y;
  real_T c2_occ_x;
  real_T c2_pcc_x;
  real_T c2_xp_a;
  real_T c2_tr_b;
  real_T c2_ot_y;
  real_T c2_qcc_x;
  real_T c2_rcc_x;
  real_T c2_scc_x;
  real_T c2_tcc_x;
  real_T c2_yp_a;
  real_T c2_ur_b;
  real_T c2_pt_y;
  real_T c2_ucc_x;
  real_T c2_vcc_x;
  real_T c2_aq_a;
  real_T c2_vr_b;
  real_T c2_qt_y;
  real_T c2_bq_a;
  real_T c2_wr_b;
  real_T c2_rt_y;
  real_T c2_wcc_x;
  real_T c2_xcc_x;
  real_T c2_ycc_x;
  real_T c2_adc_x;
  real_T c2_bdc_x;
  real_T c2_cdc_x;
  real_T c2_cq_a;
  real_T c2_xr_b;
  real_T c2_st_y;
  real_T c2_ddc_x;
  real_T c2_edc_x;
  real_T c2_dq_a;
  real_T c2_yr_b;
  real_T c2_tt_y;
  real_T c2_fdc_x;
  real_T c2_gdc_x;
  real_T c2_hdc_x;
  real_T c2_idc_x;
  real_T c2_eq_a;
  real_T c2_as_b;
  real_T c2_ut_y;
  real_T c2_jdc_x;
  real_T c2_kdc_x;
  real_T c2_fq_a;
  real_T c2_bs_b;
  real_T c2_vt_y;
  real_T c2_gq_a;
  real_T c2_cs_b;
  real_T c2_wt_y;
  real_T c2_hq_a;
  real_T c2_ds_b;
  real_T c2_xt_y;
  real_T c2_ub_A;
  real_T c2_ldc_x;
  real_T c2_mdc_x;
  real_T c2_yt_y;
  real_T c2_ndc_x;
  real_T c2_odc_x;
  real_T c2_es_b;
  real_T c2_au_y;
  real_T c2_pdc_x;
  real_T c2_qdc_x;
  real_T c2_iq_a;
  real_T c2_fs_b;
  real_T c2_bu_y;
  real_T c2_rdc_x;
  real_T c2_sdc_x;
  real_T c2_jq_a;
  real_T c2_gs_b;
  real_T c2_cu_y;
  real_T c2_vb_A;
  real_T c2_tdc_x;
  real_T c2_udc_x;
  real_T c2_du_y;
  real_T c2_vdc_x;
  real_T c2_wdc_x;
  real_T c2_hs_b;
  real_T c2_eu_y;
  real_T c2_xdc_x;
  real_T c2_ydc_x;
  real_T c2_kq_a;
  real_T c2_is_b;
  real_T c2_fu_y;
  real_T c2_aec_x;
  real_T c2_bec_x;
  real_T c2_lq_a;
  real_T c2_js_b;
  real_T c2_gu_y;
  real_T c2_wb_A;
  real_T c2_cec_x;
  real_T c2_dec_x;
  real_T c2_hu_y;
  real_T c2_eec_x;
  real_T c2_fec_x;
  real_T c2_ks_b;
  real_T c2_iu_y;
  real_T c2_gec_x;
  real_T c2_hec_x;
  real_T c2_iec_x;
  real_T c2_jec_x;
  real_T c2_mq_a;
  real_T c2_ls_b;
  real_T c2_ju_y;
  real_T c2_kec_x;
  real_T c2_lec_x;
  real_T c2_nq_a;
  real_T c2_ms_b;
  real_T c2_ku_y;
  real_T c2_mec_x;
  real_T c2_nec_x;
  real_T c2_oec_x;
  real_T c2_pec_x;
  real_T c2_oq_a;
  real_T c2_ns_b;
  real_T c2_lu_y;
  real_T c2_qec_x;
  real_T c2_rec_x;
  real_T c2_pq_a;
  real_T c2_os_b;
  real_T c2_mu_y;
  real_T c2_qq_a;
  real_T c2_ps_b;
  real_T c2_nu_y;
  real_T c2_xb_A;
  real_T c2_sec_x;
  real_T c2_tec_x;
  real_T c2_ou_y;
  real_T c2_uec_x;
  real_T c2_vec_x;
  real_T c2_qs_b;
  real_T c2_pu_y;
  real_T c2_wec_x;
  real_T c2_xec_x;
  real_T c2_rq_a;
  real_T c2_rs_b;
  real_T c2_qu_y;
  real_T c2_yb_A;
  real_T c2_yec_x;
  real_T c2_afc_x;
  real_T c2_ru_y;
  real_T c2_bfc_x;
  real_T c2_cfc_x;
  real_T c2_ss_b;
  real_T c2_su_y;
  real_T c2_dfc_x;
  real_T c2_efc_x;
  real_T c2_sq_a;
  real_T c2_ts_b;
  real_T c2_tu_y;
  real_T c2_ac_A;
  real_T c2_ffc_x;
  real_T c2_gfc_x;
  real_T c2_uu_y;
  real_T c2_hfc_x;
  real_T c2_ifc_x;
  real_T c2_us_b;
  real_T c2_vu_y;
  real_T c2_bc_A;
  real_T c2_jfc_x;
  real_T c2_kfc_x;
  real_T c2_wu_y;
  real_T c2_lfc_x;
  real_T c2_mfc_x;
  real_T c2_vs_b;
  real_T c2_xu_y;
  real_T c2_nfc_x;
  real_T c2_ofc_x;
  real_T c2_pfc_x;
  real_T c2_qfc_x;
  real_T c2_tq_a;
  real_T c2_ws_b;
  real_T c2_yu_y;
  real_T c2_rfc_x;
  real_T c2_sfc_x;
  real_T c2_uq_a;
  real_T c2_xs_b;
  real_T c2_av_y;
  real_T c2_tfc_x;
  real_T c2_ufc_x;
  real_T c2_vfc_x;
  real_T c2_wfc_x;
  real_T c2_vq_a;
  real_T c2_ys_b;
  real_T c2_bv_y;
  real_T c2_xfc_x;
  real_T c2_yfc_x;
  real_T c2_wq_a;
  real_T c2_at_b;
  real_T c2_cv_y;
  real_T c2_xq_a;
  real_T c2_bt_b;
  real_T c2_dv_y;
  real_T c2_cc_A;
  real_T c2_agc_x;
  real_T c2_bgc_x;
  real_T c2_ev_y;
  real_T c2_cgc_x;
  real_T c2_dgc_x;
  real_T c2_ct_b;
  real_T c2_fv_y;
  real_T c2_egc_x;
  real_T c2_fgc_x;
  real_T c2_ggc_x;
  real_T c2_hgc_x;
  real_T c2_igc_x;
  real_T c2_jgc_x;
  real_T c2_yq_a;
  real_T c2_dt_b;
  real_T c2_gv_y;
  real_T c2_kgc_x;
  real_T c2_lgc_x;
  real_T c2_ar_a;
  real_T c2_et_b;
  real_T c2_hv_y;
  real_T c2_mgc_x;
  real_T c2_ngc_x;
  real_T c2_ogc_x;
  real_T c2_pgc_x;
  real_T c2_br_a;
  real_T c2_ft_b;
  real_T c2_iv_y;
  real_T c2_qgc_x;
  real_T c2_rgc_x;
  real_T c2_cr_a;
  real_T c2_gt_b;
  real_T c2_jv_y;
  real_T c2_dr_a;
  real_T c2_ht_b;
  real_T c2_kv_y;
  real_T c2_sgc_x;
  real_T c2_tgc_x;
  real_T c2_ugc_x;
  real_T c2_vgc_x;
  real_T c2_wgc_x;
  real_T c2_xgc_x;
  real_T c2_er_a;
  real_T c2_it_b;
  real_T c2_lv_y;
  real_T c2_ygc_x;
  real_T c2_ahc_x;
  real_T c2_fr_a;
  real_T c2_jt_b;
  real_T c2_mv_y;
  real_T c2_bhc_x;
  real_T c2_chc_x;
  real_T c2_dhc_x;
  real_T c2_ehc_x;
  real_T c2_gr_a;
  real_T c2_kt_b;
  real_T c2_nv_y;
  real_T c2_fhc_x;
  real_T c2_ghc_x;
  real_T c2_hr_a;
  real_T c2_lt_b;
  real_T c2_ov_y;
  real_T c2_ir_a;
  real_T c2_mt_b;
  real_T c2_pv_y;
  real_T c2_jr_a;
  real_T c2_nt_b;
  real_T c2_qv_y;
  real_T c2_dc_A;
  real_T c2_hhc_x;
  real_T c2_ihc_x;
  real_T c2_rv_y;
  real_T c2_jhc_x;
  real_T c2_khc_x;
  real_T c2_ot_b;
  real_T c2_sv_y;
  real_T c2_lhc_x;
  real_T c2_mhc_x;
  real_T c2_kr_a;
  real_T c2_pt_b;
  real_T c2_tv_y;
  real_T c2_nhc_x;
  real_T c2_ohc_x;
  real_T c2_lr_a;
  real_T c2_qt_b;
  real_T c2_uv_y;
  real_T c2_ec_A;
  real_T c2_phc_x;
  real_T c2_qhc_x;
  real_T c2_vv_y;
  real_T c2_rhc_x;
  real_T c2_shc_x;
  real_T c2_rt_b;
  real_T c2_wv_y;
  real_T c2_thc_x;
  real_T c2_uhc_x;
  real_T c2_mr_a;
  real_T c2_st_b;
  real_T c2_xv_y;
  real_T c2_vhc_x;
  real_T c2_whc_x;
  real_T c2_nr_a;
  real_T c2_tt_b;
  real_T c2_yv_y;
  real_T c2_fc_A;
  real_T c2_xhc_x;
  real_T c2_yhc_x;
  real_T c2_aw_y;
  real_T c2_aic_x;
  real_T c2_bic_x;
  real_T c2_ut_b;
  real_T c2_bw_y;
  real_T c2_cic_x;
  real_T c2_dic_x;
  real_T c2_eic_x;
  real_T c2_fic_x;
  real_T c2_or_a;
  real_T c2_vt_b;
  real_T c2_cw_y;
  real_T c2_gic_x;
  real_T c2_hic_x;
  real_T c2_iic_x;
  real_T c2_jic_x;
  real_T c2_pr_a;
  real_T c2_wt_b;
  real_T c2_dw_y;
  real_T c2_qr_a;
  real_T c2_xt_b;
  real_T c2_ew_y;
  real_T c2_gc_A;
  real_T c2_kic_x;
  real_T c2_lic_x;
  real_T c2_fw_y;
  real_T c2_mic_x;
  real_T c2_nic_x;
  real_T c2_yt_b;
  real_T c2_gw_y;
  real_T c2_oic_x;
  real_T c2_pic_x;
  real_T c2_rr_a;
  real_T c2_au_b;
  real_T c2_hw_y;
  real_T c2_hc_A;
  real_T c2_qic_x;
  real_T c2_ric_x;
  real_T c2_iw_y;
  real_T c2_sic_x;
  real_T c2_tic_x;
  real_T c2_bu_b;
  real_T c2_jw_y;
  real_T c2_uic_x;
  real_T c2_vic_x;
  real_T c2_sr_a;
  real_T c2_cu_b;
  real_T c2_kw_y;
  real_T c2_ic_A;
  real_T c2_wic_x;
  real_T c2_xic_x;
  real_T c2_lw_y;
  real_T c2_yic_x;
  real_T c2_ajc_x;
  real_T c2_du_b;
  real_T c2_mw_y;
  real_T c2_bjc_x;
  real_T c2_cjc_x;
  real_T c2_djc_x;
  real_T c2_ejc_x;
  real_T c2_fjc_x;
  real_T c2_gjc_x;
  real_T c2_tr_a;
  real_T c2_eu_b;
  real_T c2_nw_y;
  real_T c2_hjc_x;
  real_T c2_ijc_x;
  real_T c2_jjc_x;
  real_T c2_kjc_x;
  real_T c2_ur_a;
  real_T c2_fu_b;
  real_T c2_ow_y;
  real_T c2_vr_a;
  real_T c2_gu_b;
  real_T c2_pw_y;
  real_T c2_ljc_x;
  real_T c2_mjc_x;
  real_T c2_njc_x;
  real_T c2_ojc_x;
  real_T c2_pjc_x;
  real_T c2_qjc_x;
  real_T c2_wr_a;
  real_T c2_hu_b;
  real_T c2_qw_y;
  real_T c2_rjc_x;
  real_T c2_sjc_x;
  real_T c2_tjc_x;
  real_T c2_ujc_x;
  real_T c2_xr_a;
  real_T c2_iu_b;
  real_T c2_rw_y;
  real_T c2_yr_a;
  real_T c2_ju_b;
  real_T c2_sw_y;
  real_T c2_as_a;
  real_T c2_ku_b;
  real_T c2_tw_y;
  real_T c2_jc_A;
  real_T c2_vjc_x;
  real_T c2_wjc_x;
  real_T c2_uw_y;
  real_T c2_xjc_x;
  real_T c2_yjc_x;
  real_T c2_lu_b;
  real_T c2_vw_y;
  real_T c2_akc_x;
  real_T c2_bkc_x;
  real_T c2_ckc_x;
  real_T c2_dkc_x;
  real_T c2_bs_a;
  real_T c2_mu_b;
  real_T c2_ww_y;
  real_T c2_ekc_x;
  real_T c2_fkc_x;
  real_T c2_gkc_x;
  real_T c2_hkc_x;
  real_T c2_cs_a;
  real_T c2_nu_b;
  real_T c2_xw_y;
  real_T c2_ds_a;
  real_T c2_ou_b;
  real_T c2_yw_y;
  real_T c2_kc_A;
  real_T c2_ikc_x;
  real_T c2_jkc_x;
  real_T c2_ax_y;
  real_T c2_kkc_x;
  real_T c2_lkc_x;
  real_T c2_pu_b;
  real_T c2_bx_y;
  real_T c2_lc_A;
  real_T c2_mkc_x;
  real_T c2_nkc_x;
  real_T c2_cx_y;
  int32_T c2_i29;
  real_T c2_es_a[9];
  int32_T c2_i30;
  real_T c2_dx_y[3];
  int32_T c2_i31;
  int32_T c2_i32;
  static real_T c2_qu_b[3] = { 0.0, -0.02561, 0.00193 };

  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  static real_T c2_ru_b[3] = { 0.2125, 0.0, 0.11336 };

  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  static real_T c2_su_b[3] = { 0.11993, 0.0, 0.0265 };

  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  static real_T c2_tu_b[3] = { 0.0, -0.0018, 0.01634 };

  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  static real_T c2_uu_b[3] = { 0.0, 0.0018, 0.01634 };

  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  static real_T c2_vu_b[3] = { 0.0, 0.0, -0.001159 };

  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  real_T (*c2_b_r0_c1)[3];
  real_T (*c2_b_r0_c2)[3];
  real_T (*c2_b_r0_c3)[3];
  real_T (*c2_b_r0_c4)[3];
  real_T (*c2_b_r0_c5)[3];
  real_T (*c2_b_r0_c6)[3];
  real_T (*c2_b_q)[6];
  c2_b_r0_c6 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_b_r0_c5 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_b_r0_c4 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_r0_c3 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_r0_c2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_r0_c1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i19 = 0; c2_i19 < 6; c2_i19++) {
    c2_q[c2_i19] = (*c2_b_q)[c2_i19];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta_1, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta_2, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta_3, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta_4, 3U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta_5, 4U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta_6, 5U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_r1_c1, 6U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_r2_c2, 7U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_r3_c3, 8U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_r4_c4, 9U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_r5_c5, 10U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_r6_c6, 11U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R1, 12U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R2, 13U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R3, 14U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R4, 15U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R5, 16U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R6, 17U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d1, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d2, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d3, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d4, 21U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d5, 22U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d6, 23U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 24U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 25U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_q, 26U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_r0_c1, 27U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_r0_c2, 28U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_r0_c3, 29U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_r0_c4, 30U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_r0_c5, 31U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_r0_c6, 32U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_theta_1 = c2_q[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_theta_2 = c2_q[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_theta_3 = c2_q[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_theta_4 = c2_q[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_theta_5 = c2_q[4];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_theta_6 = c2_q[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
    c2_r1_c1[c2_i20] = c2_dv6[c2_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
    c2_r2_c2[c2_i21] = c2_dv7[c2_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
    c2_r3_c3[c2_i22] = c2_dv8[c2_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    c2_r4_c4[c2_i23] = c2_dv9[c2_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
    c2_r5_c5[c2_i24] = c2_dv10[c2_i24];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  for (c2_i25 = 0; c2_i25 < 3; c2_i25++) {
    c2_r6_c6[c2_i25] = c2_dv11[c2_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_x = c2_theta_1;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_theta_1;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_e_x = c2_theta_1;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_theta_1;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_R1[0] = c2_b_x;
  c2_R1[3] = 0.0;
  c2_R1[6] = c2_d_x;
  c2_R1[1] = c2_f_x;
  c2_R1[4] = 0.0;
  c2_R1[7] = -c2_h_x;
  c2_i26 = 0;
  for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
    c2_R1[c2_i26 + 2] = c2_dv12[c2_i27];
    c2_i26 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_i_x = c2_theta_1;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarCos(c2_j_x);
  c2_k_x = c2_theta_2;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarCos(c2_l_x);
  c2_a = c2_j_x;
  c2_b = c2_l_x;
  c2_y = c2_a * c2_b;
  c2_m_x = c2_theta_1;
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarCos(c2_n_x);
  c2_o_x = c2_theta_2;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarSin(c2_p_x);
  c2_b_a = -c2_n_x;
  c2_b_b = c2_p_x;
  c2_b_y = c2_b_a * c2_b_b;
  c2_q_x = c2_theta_1;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarSin(c2_r_x);
  c2_s_x = c2_theta_2;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_u_x = c2_theta_1;
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarSin(c2_v_x);
  c2_c_a = c2_t_x;
  c2_c_b = c2_v_x;
  c2_c_y = c2_c_a * c2_c_b;
  c2_w_x = c2_theta_1;
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarSin(c2_x_x);
  c2_y_x = c2_theta_2;
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarSin(c2_ab_x);
  c2_d_a = -c2_x_x;
  c2_d_b = c2_ab_x;
  c2_d_y = c2_d_a * c2_d_b;
  c2_bb_x = c2_theta_1;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarCos(c2_cb_x);
  c2_db_x = c2_theta_2;
  c2_eb_x = c2_db_x;
  c2_eb_x = muDoubleScalarSin(c2_eb_x);
  c2_fb_x = c2_theta_2;
  c2_gb_x = c2_fb_x;
  c2_gb_x = muDoubleScalarCos(c2_gb_x);
  c2_R2[0] = c2_y;
  c2_R2[3] = c2_b_y;
  c2_R2[6] = c2_r_x;
  c2_R2[1] = c2_c_y;
  c2_R2[4] = c2_d_y;
  c2_R2[7] = -c2_cb_x;
  c2_R2[2] = c2_eb_x;
  c2_R2[5] = c2_gb_x;
  c2_R2[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_hb_x = c2_theta_1;
  c2_ib_x = c2_hb_x;
  c2_ib_x = muDoubleScalarCos(c2_ib_x);
  c2_jb_x = c2_theta_2;
  c2_kb_x = c2_jb_x;
  c2_kb_x = muDoubleScalarCos(c2_kb_x);
  c2_e_a = c2_ib_x;
  c2_e_b = c2_kb_x;
  c2_e_y = c2_e_a * c2_e_b;
  c2_lb_x = c2_theta_3;
  c2_mb_x = c2_lb_x;
  c2_mb_x = muDoubleScalarCos(c2_mb_x);
  c2_f_a = c2_e_y;
  c2_f_b = c2_mb_x;
  c2_f_y = c2_f_a * c2_f_b;
  c2_nb_x = c2_theta_1;
  c2_ob_x = c2_nb_x;
  c2_ob_x = muDoubleScalarCos(c2_ob_x);
  c2_pb_x = c2_theta_2;
  c2_qb_x = c2_pb_x;
  c2_qb_x = muDoubleScalarSin(c2_qb_x);
  c2_g_a = c2_ob_x;
  c2_g_b = c2_qb_x;
  c2_g_y = c2_g_a * c2_g_b;
  c2_rb_x = c2_theta_3;
  c2_sb_x = c2_rb_x;
  c2_sb_x = muDoubleScalarSin(c2_sb_x);
  c2_h_a = c2_g_y;
  c2_h_b = c2_sb_x;
  c2_h_y = c2_h_a * c2_h_b;
  c2_tb_x = c2_theta_1;
  c2_ub_x = c2_tb_x;
  c2_ub_x = muDoubleScalarCos(c2_ub_x);
  c2_vb_x = c2_theta_2;
  c2_wb_x = c2_vb_x;
  c2_wb_x = muDoubleScalarCos(c2_wb_x);
  c2_i_a = -c2_ub_x;
  c2_i_b = c2_wb_x;
  c2_i_y = c2_i_a * c2_i_b;
  c2_xb_x = c2_theta_3;
  c2_yb_x = c2_xb_x;
  c2_yb_x = muDoubleScalarSin(c2_yb_x);
  c2_j_a = c2_i_y;
  c2_j_b = c2_yb_x;
  c2_j_y = c2_j_a * c2_j_b;
  c2_ac_x = c2_theta_1;
  c2_bc_x = c2_ac_x;
  c2_bc_x = muDoubleScalarCos(c2_bc_x);
  c2_cc_x = c2_theta_3;
  c2_dc_x = c2_cc_x;
  c2_dc_x = muDoubleScalarCos(c2_dc_x);
  c2_k_a = c2_bc_x;
  c2_k_b = c2_dc_x;
  c2_k_y = c2_k_a * c2_k_b;
  c2_ec_x = c2_theta_2;
  c2_fc_x = c2_ec_x;
  c2_fc_x = muDoubleScalarSin(c2_fc_x);
  c2_l_a = c2_k_y;
  c2_l_b = c2_fc_x;
  c2_l_y = c2_l_a * c2_l_b;
  c2_gc_x = c2_theta_1;
  c2_hc_x = c2_gc_x;
  c2_hc_x = muDoubleScalarSin(c2_hc_x);
  c2_ic_x = c2_theta_2;
  c2_jc_x = c2_ic_x;
  c2_jc_x = muDoubleScalarCos(c2_jc_x);
  c2_kc_x = c2_theta_3;
  c2_lc_x = c2_kc_x;
  c2_lc_x = muDoubleScalarCos(c2_lc_x);
  c2_m_a = c2_jc_x;
  c2_m_b = c2_lc_x;
  c2_m_y = c2_m_a * c2_m_b;
  c2_mc_x = c2_theta_1;
  c2_nc_x = c2_mc_x;
  c2_nc_x = muDoubleScalarSin(c2_nc_x);
  c2_n_a = c2_m_y;
  c2_n_b = c2_nc_x;
  c2_n_y = c2_n_a * c2_n_b;
  c2_oc_x = c2_theta_1;
  c2_pc_x = c2_oc_x;
  c2_pc_x = muDoubleScalarSin(c2_pc_x);
  c2_qc_x = c2_theta_2;
  c2_rc_x = c2_qc_x;
  c2_rc_x = muDoubleScalarSin(c2_rc_x);
  c2_o_a = c2_pc_x;
  c2_o_b = c2_rc_x;
  c2_o_y = c2_o_a * c2_o_b;
  c2_sc_x = c2_theta_3;
  c2_tc_x = c2_sc_x;
  c2_tc_x = muDoubleScalarSin(c2_tc_x);
  c2_p_a = c2_o_y;
  c2_p_b = c2_tc_x;
  c2_p_y = c2_p_a * c2_p_b;
  c2_uc_x = c2_theta_2;
  c2_vc_x = c2_uc_x;
  c2_vc_x = muDoubleScalarCos(c2_vc_x);
  c2_wc_x = c2_theta_1;
  c2_xc_x = c2_wc_x;
  c2_xc_x = muDoubleScalarSin(c2_xc_x);
  c2_q_a = -c2_vc_x;
  c2_q_b = c2_xc_x;
  c2_q_y = c2_q_a * c2_q_b;
  c2_yc_x = c2_theta_3;
  c2_ad_x = c2_yc_x;
  c2_ad_x = muDoubleScalarSin(c2_ad_x);
  c2_r_a = c2_q_y;
  c2_r_b = c2_ad_x;
  c2_r_y = c2_r_a * c2_r_b;
  c2_bd_x = c2_theta_3;
  c2_cd_x = c2_bd_x;
  c2_cd_x = muDoubleScalarCos(c2_cd_x);
  c2_dd_x = c2_theta_1;
  c2_ed_x = c2_dd_x;
  c2_ed_x = muDoubleScalarSin(c2_ed_x);
  c2_s_a = c2_cd_x;
  c2_s_b = c2_ed_x;
  c2_s_y = c2_s_a * c2_s_b;
  c2_fd_x = c2_theta_2;
  c2_gd_x = c2_fd_x;
  c2_gd_x = muDoubleScalarSin(c2_gd_x);
  c2_t_a = c2_s_y;
  c2_t_b = c2_gd_x;
  c2_t_y = c2_t_a * c2_t_b;
  c2_hd_x = c2_theta_1;
  c2_id_x = c2_hd_x;
  c2_id_x = muDoubleScalarCos(c2_id_x);
  c2_jd_x = c2_theta_2;
  c2_kd_x = c2_jd_x;
  c2_kd_x = muDoubleScalarCos(c2_kd_x);
  c2_ld_x = c2_theta_3;
  c2_md_x = c2_ld_x;
  c2_md_x = muDoubleScalarSin(c2_md_x);
  c2_u_a = c2_kd_x;
  c2_u_b = c2_md_x;
  c2_u_y = c2_u_a * c2_u_b;
  c2_nd_x = c2_theta_3;
  c2_od_x = c2_nd_x;
  c2_od_x = muDoubleScalarCos(c2_od_x);
  c2_pd_x = c2_theta_2;
  c2_qd_x = c2_pd_x;
  c2_qd_x = muDoubleScalarSin(c2_qd_x);
  c2_v_a = c2_od_x;
  c2_v_b = c2_qd_x;
  c2_v_y = c2_v_a * c2_v_b;
  c2_rd_x = c2_theta_2;
  c2_sd_x = c2_rd_x;
  c2_sd_x = muDoubleScalarCos(c2_sd_x);
  c2_td_x = c2_theta_3;
  c2_ud_x = c2_td_x;
  c2_ud_x = muDoubleScalarCos(c2_ud_x);
  c2_w_a = c2_sd_x;
  c2_w_b = c2_ud_x;
  c2_w_y = c2_w_a * c2_w_b;
  c2_vd_x = c2_theta_2;
  c2_wd_x = c2_vd_x;
  c2_wd_x = muDoubleScalarSin(c2_wd_x);
  c2_xd_x = c2_theta_3;
  c2_yd_x = c2_xd_x;
  c2_yd_x = muDoubleScalarSin(c2_yd_x);
  c2_x_a = c2_wd_x;
  c2_x_b = c2_yd_x;
  c2_x_y = c2_x_a * c2_x_b;
  c2_R3[0] = c2_f_y - c2_h_y;
  c2_R3[3] = c2_j_y - c2_l_y;
  c2_R3[6] = c2_hc_x;
  c2_R3[1] = c2_n_y - c2_p_y;
  c2_R3[4] = c2_r_y - c2_t_y;
  c2_R3[7] = -c2_id_x;
  c2_R3[2] = c2_u_y + c2_v_y;
  c2_R3[5] = c2_w_y - c2_x_y;
  c2_R3[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_ae_x = c2_theta_4;
  c2_be_x = c2_ae_x;
  c2_be_x = muDoubleScalarCos(c2_be_x);
  c2_ce_x = c2_theta_1;
  c2_de_x = c2_ce_x;
  c2_de_x = muDoubleScalarCos(c2_de_x);
  c2_ee_x = c2_theta_2;
  c2_fe_x = c2_ee_x;
  c2_fe_x = muDoubleScalarSin(c2_fe_x);
  c2_y_a = c2_de_x;
  c2_y_b = c2_fe_x;
  c2_y_y = c2_y_a * c2_y_b;
  c2_ge_x = c2_theta_3;
  c2_he_x = c2_ge_x;
  c2_he_x = muDoubleScalarSin(c2_he_x);
  c2_ab_a = c2_y_y;
  c2_ab_b = c2_he_x;
  c2_ab_y = c2_ab_a * c2_ab_b;
  c2_ie_x = c2_theta_1;
  c2_je_x = c2_ie_x;
  c2_je_x = muDoubleScalarCos(c2_je_x);
  c2_ke_x = c2_theta_2;
  c2_le_x = c2_ke_x;
  c2_le_x = muDoubleScalarCos(c2_le_x);
  c2_bb_a = c2_je_x;
  c2_bb_b = c2_le_x;
  c2_bb_y = c2_bb_a * c2_bb_b;
  c2_me_x = c2_theta_3;
  c2_ne_x = c2_me_x;
  c2_ne_x = muDoubleScalarCos(c2_ne_x);
  c2_cb_a = c2_bb_y;
  c2_cb_b = c2_ne_x;
  c2_cb_y = c2_cb_a * c2_cb_b;
  c2_db_a = -c2_be_x;
  c2_db_b = c2_ab_y - c2_cb_y;
  c2_db_y = c2_db_a * c2_db_b;
  c2_oe_x = c2_theta_4;
  c2_pe_x = c2_oe_x;
  c2_pe_x = muDoubleScalarSin(c2_pe_x);
  c2_qe_x = c2_theta_1;
  c2_re_x = c2_qe_x;
  c2_re_x = muDoubleScalarCos(c2_re_x);
  c2_se_x = c2_theta_2;
  c2_te_x = c2_se_x;
  c2_te_x = muDoubleScalarCos(c2_te_x);
  c2_eb_a = c2_re_x;
  c2_eb_b = c2_te_x;
  c2_eb_y = c2_eb_a * c2_eb_b;
  c2_ue_x = c2_theta_3;
  c2_ve_x = c2_ue_x;
  c2_ve_x = muDoubleScalarSin(c2_ve_x);
  c2_fb_a = c2_eb_y;
  c2_fb_b = c2_ve_x;
  c2_fb_y = c2_fb_a * c2_fb_b;
  c2_we_x = c2_theta_1;
  c2_xe_x = c2_we_x;
  c2_xe_x = muDoubleScalarCos(c2_xe_x);
  c2_ye_x = c2_theta_3;
  c2_af_x = c2_ye_x;
  c2_af_x = muDoubleScalarCos(c2_af_x);
  c2_gb_a = c2_xe_x;
  c2_gb_b = c2_af_x;
  c2_gb_y = c2_gb_a * c2_gb_b;
  c2_bf_x = c2_theta_2;
  c2_cf_x = c2_bf_x;
  c2_cf_x = muDoubleScalarSin(c2_cf_x);
  c2_hb_a = c2_gb_y;
  c2_hb_b = c2_cf_x;
  c2_hb_y = c2_hb_a * c2_hb_b;
  c2_ib_a = c2_pe_x;
  c2_ib_b = c2_fb_y + c2_hb_y;
  c2_ib_y = c2_ib_a * c2_ib_b;
  c2_df_x = c2_theta_1;
  c2_ef_x = c2_df_x;
  c2_ef_x = muDoubleScalarSin(c2_ef_x);
  c2_ff_x = c2_theta_4;
  c2_gf_x = c2_ff_x;
  c2_gf_x = muDoubleScalarCos(c2_gf_x);
  c2_hf_x = c2_theta_1;
  c2_if_x = c2_hf_x;
  c2_if_x = muDoubleScalarCos(c2_if_x);
  c2_jf_x = c2_theta_2;
  c2_kf_x = c2_jf_x;
  c2_kf_x = muDoubleScalarCos(c2_kf_x);
  c2_jb_a = c2_if_x;
  c2_jb_b = c2_kf_x;
  c2_jb_y = c2_jb_a * c2_jb_b;
  c2_lf_x = c2_theta_3;
  c2_mf_x = c2_lf_x;
  c2_mf_x = muDoubleScalarSin(c2_mf_x);
  c2_kb_a = c2_jb_y;
  c2_kb_b = c2_mf_x;
  c2_kb_y = c2_kb_a * c2_kb_b;
  c2_nf_x = c2_theta_1;
  c2_of_x = c2_nf_x;
  c2_of_x = muDoubleScalarCos(c2_of_x);
  c2_pf_x = c2_theta_3;
  c2_qf_x = c2_pf_x;
  c2_qf_x = muDoubleScalarCos(c2_qf_x);
  c2_lb_a = c2_of_x;
  c2_lb_b = c2_qf_x;
  c2_lb_y = c2_lb_a * c2_lb_b;
  c2_rf_x = c2_theta_2;
  c2_sf_x = c2_rf_x;
  c2_sf_x = muDoubleScalarSin(c2_sf_x);
  c2_mb_a = c2_lb_y;
  c2_mb_b = c2_sf_x;
  c2_mb_y = c2_mb_a * c2_mb_b;
  c2_nb_a = c2_gf_x;
  c2_nb_b = c2_kb_y + c2_mb_y;
  c2_nb_y = c2_nb_a * c2_nb_b;
  c2_tf_x = c2_theta_4;
  c2_uf_x = c2_tf_x;
  c2_uf_x = muDoubleScalarSin(c2_uf_x);
  c2_vf_x = c2_theta_1;
  c2_wf_x = c2_vf_x;
  c2_wf_x = muDoubleScalarCos(c2_wf_x);
  c2_xf_x = c2_theta_2;
  c2_yf_x = c2_xf_x;
  c2_yf_x = muDoubleScalarSin(c2_yf_x);
  c2_ob_a = c2_wf_x;
  c2_ob_b = c2_yf_x;
  c2_ob_y = c2_ob_a * c2_ob_b;
  c2_ag_x = c2_theta_3;
  c2_bg_x = c2_ag_x;
  c2_bg_x = muDoubleScalarSin(c2_bg_x);
  c2_pb_a = c2_ob_y;
  c2_pb_b = c2_bg_x;
  c2_pb_y = c2_pb_a * c2_pb_b;
  c2_cg_x = c2_theta_1;
  c2_dg_x = c2_cg_x;
  c2_dg_x = muDoubleScalarCos(c2_dg_x);
  c2_eg_x = c2_theta_2;
  c2_fg_x = c2_eg_x;
  c2_fg_x = muDoubleScalarCos(c2_fg_x);
  c2_qb_a = c2_dg_x;
  c2_qb_b = c2_fg_x;
  c2_qb_y = c2_qb_a * c2_qb_b;
  c2_gg_x = c2_theta_3;
  c2_hg_x = c2_gg_x;
  c2_hg_x = muDoubleScalarCos(c2_hg_x);
  c2_rb_a = c2_qb_y;
  c2_rb_b = c2_hg_x;
  c2_rb_y = c2_rb_a * c2_rb_b;
  c2_sb_a = c2_uf_x;
  c2_sb_b = c2_pb_y - c2_rb_y;
  c2_sb_y = c2_sb_a * c2_sb_b;
  c2_ig_x = c2_theta_4;
  c2_jg_x = c2_ig_x;
  c2_jg_x = muDoubleScalarCos(c2_jg_x);
  c2_kg_x = c2_theta_1;
  c2_lg_x = c2_kg_x;
  c2_lg_x = muDoubleScalarSin(c2_lg_x);
  c2_mg_x = c2_theta_2;
  c2_ng_x = c2_mg_x;
  c2_ng_x = muDoubleScalarSin(c2_ng_x);
  c2_tb_a = c2_lg_x;
  c2_tb_b = c2_ng_x;
  c2_tb_y = c2_tb_a * c2_tb_b;
  c2_og_x = c2_theta_3;
  c2_pg_x = c2_og_x;
  c2_pg_x = muDoubleScalarSin(c2_pg_x);
  c2_ub_a = c2_tb_y;
  c2_ub_b = c2_pg_x;
  c2_ub_y = c2_ub_a * c2_ub_b;
  c2_qg_x = c2_theta_2;
  c2_rg_x = c2_qg_x;
  c2_rg_x = muDoubleScalarCos(c2_rg_x);
  c2_sg_x = c2_theta_3;
  c2_tg_x = c2_sg_x;
  c2_tg_x = muDoubleScalarCos(c2_tg_x);
  c2_vb_a = c2_rg_x;
  c2_vb_b = c2_tg_x;
  c2_vb_y = c2_vb_a * c2_vb_b;
  c2_ug_x = c2_theta_1;
  c2_vg_x = c2_ug_x;
  c2_vg_x = muDoubleScalarSin(c2_vg_x);
  c2_wb_a = c2_vb_y;
  c2_wb_b = c2_vg_x;
  c2_wb_y = c2_wb_a * c2_wb_b;
  c2_xb_a = -c2_jg_x;
  c2_xb_b = c2_ub_y - c2_wb_y;
  c2_xb_y = c2_xb_a * c2_xb_b;
  c2_wg_x = c2_theta_4;
  c2_xg_x = c2_wg_x;
  c2_xg_x = muDoubleScalarSin(c2_xg_x);
  c2_yg_x = c2_theta_2;
  c2_ah_x = c2_yg_x;
  c2_ah_x = muDoubleScalarCos(c2_ah_x);
  c2_bh_x = c2_theta_1;
  c2_ch_x = c2_bh_x;
  c2_ch_x = muDoubleScalarSin(c2_ch_x);
  c2_yb_a = c2_ah_x;
  c2_yb_b = c2_ch_x;
  c2_yb_y = c2_yb_a * c2_yb_b;
  c2_dh_x = c2_theta_3;
  c2_eh_x = c2_dh_x;
  c2_eh_x = muDoubleScalarSin(c2_eh_x);
  c2_ac_a = c2_yb_y;
  c2_ac_b = c2_eh_x;
  c2_ac_y = c2_ac_a * c2_ac_b;
  c2_fh_x = c2_theta_3;
  c2_gh_x = c2_fh_x;
  c2_gh_x = muDoubleScalarCos(c2_gh_x);
  c2_hh_x = c2_theta_1;
  c2_ih_x = c2_hh_x;
  c2_ih_x = muDoubleScalarSin(c2_ih_x);
  c2_bc_a = c2_gh_x;
  c2_bc_b = c2_ih_x;
  c2_bc_y = c2_bc_a * c2_bc_b;
  c2_jh_x = c2_theta_2;
  c2_kh_x = c2_jh_x;
  c2_kh_x = muDoubleScalarSin(c2_kh_x);
  c2_cc_a = c2_bc_y;
  c2_cc_b = c2_kh_x;
  c2_cc_y = c2_cc_a * c2_cc_b;
  c2_dc_a = c2_xg_x;
  c2_dc_b = c2_ac_y + c2_cc_y;
  c2_dc_y = c2_dc_a * c2_dc_b;
  c2_lh_x = c2_theta_1;
  c2_mh_x = c2_lh_x;
  c2_mh_x = muDoubleScalarCos(c2_mh_x);
  c2_nh_x = c2_theta_4;
  c2_oh_x = c2_nh_x;
  c2_oh_x = muDoubleScalarCos(c2_oh_x);
  c2_ph_x = c2_theta_2;
  c2_qh_x = c2_ph_x;
  c2_qh_x = muDoubleScalarCos(c2_qh_x);
  c2_rh_x = c2_theta_1;
  c2_sh_x = c2_rh_x;
  c2_sh_x = muDoubleScalarSin(c2_sh_x);
  c2_ec_a = c2_qh_x;
  c2_ec_b = c2_sh_x;
  c2_ec_y = c2_ec_a * c2_ec_b;
  c2_th_x = c2_theta_3;
  c2_uh_x = c2_th_x;
  c2_uh_x = muDoubleScalarSin(c2_uh_x);
  c2_fc_a = c2_ec_y;
  c2_fc_b = c2_uh_x;
  c2_fc_y = c2_fc_a * c2_fc_b;
  c2_vh_x = c2_theta_3;
  c2_wh_x = c2_vh_x;
  c2_wh_x = muDoubleScalarCos(c2_wh_x);
  c2_xh_x = c2_theta_1;
  c2_yh_x = c2_xh_x;
  c2_yh_x = muDoubleScalarSin(c2_yh_x);
  c2_gc_a = c2_wh_x;
  c2_gc_b = c2_yh_x;
  c2_gc_y = c2_gc_a * c2_gc_b;
  c2_ai_x = c2_theta_2;
  c2_bi_x = c2_ai_x;
  c2_bi_x = muDoubleScalarSin(c2_bi_x);
  c2_hc_a = c2_gc_y;
  c2_hc_b = c2_bi_x;
  c2_hc_y = c2_hc_a * c2_hc_b;
  c2_ic_a = c2_oh_x;
  c2_ic_b = c2_fc_y + c2_hc_y;
  c2_ic_y = c2_ic_a * c2_ic_b;
  c2_ci_x = c2_theta_4;
  c2_di_x = c2_ci_x;
  c2_di_x = muDoubleScalarSin(c2_di_x);
  c2_ei_x = c2_theta_1;
  c2_fi_x = c2_ei_x;
  c2_fi_x = muDoubleScalarSin(c2_fi_x);
  c2_gi_x = c2_theta_2;
  c2_hi_x = c2_gi_x;
  c2_hi_x = muDoubleScalarSin(c2_hi_x);
  c2_jc_a = c2_fi_x;
  c2_jc_b = c2_hi_x;
  c2_jc_y = c2_jc_a * c2_jc_b;
  c2_ii_x = c2_theta_3;
  c2_ji_x = c2_ii_x;
  c2_ji_x = muDoubleScalarSin(c2_ji_x);
  c2_kc_a = c2_jc_y;
  c2_kc_b = c2_ji_x;
  c2_kc_y = c2_kc_a * c2_kc_b;
  c2_ki_x = c2_theta_2;
  c2_li_x = c2_ki_x;
  c2_li_x = muDoubleScalarCos(c2_li_x);
  c2_mi_x = c2_theta_3;
  c2_ni_x = c2_mi_x;
  c2_ni_x = muDoubleScalarCos(c2_ni_x);
  c2_lc_a = c2_li_x;
  c2_lc_b = c2_ni_x;
  c2_lc_y = c2_lc_a * c2_lc_b;
  c2_oi_x = c2_theta_1;
  c2_pi_x = c2_oi_x;
  c2_pi_x = muDoubleScalarSin(c2_pi_x);
  c2_mc_a = c2_lc_y;
  c2_mc_b = c2_pi_x;
  c2_mc_y = c2_mc_a * c2_mc_b;
  c2_nc_a = c2_di_x;
  c2_nc_b = c2_kc_y - c2_mc_y;
  c2_nc_y = c2_nc_a * c2_nc_b;
  c2_qi_x = c2_theta_4;
  c2_ri_x = c2_qi_x;
  c2_ri_x = muDoubleScalarCos(c2_ri_x);
  c2_si_x = c2_theta_2;
  c2_ti_x = c2_si_x;
  c2_ti_x = muDoubleScalarCos(c2_ti_x);
  c2_ui_x = c2_theta_3;
  c2_vi_x = c2_ui_x;
  c2_vi_x = muDoubleScalarSin(c2_vi_x);
  c2_oc_a = c2_ti_x;
  c2_oc_b = c2_vi_x;
  c2_oc_y = c2_oc_a * c2_oc_b;
  c2_wi_x = c2_theta_3;
  c2_xi_x = c2_wi_x;
  c2_xi_x = muDoubleScalarCos(c2_xi_x);
  c2_yi_x = c2_theta_2;
  c2_aj_x = c2_yi_x;
  c2_aj_x = muDoubleScalarSin(c2_aj_x);
  c2_pc_a = c2_xi_x;
  c2_pc_b = c2_aj_x;
  c2_pc_y = c2_pc_a * c2_pc_b;
  c2_qc_a = c2_ri_x;
  c2_qc_b = c2_oc_y + c2_pc_y;
  c2_qc_y = c2_qc_a * c2_qc_b;
  c2_bj_x = c2_theta_4;
  c2_cj_x = c2_bj_x;
  c2_cj_x = muDoubleScalarSin(c2_cj_x);
  c2_dj_x = c2_theta_2;
  c2_ej_x = c2_dj_x;
  c2_ej_x = muDoubleScalarCos(c2_ej_x);
  c2_fj_x = c2_theta_3;
  c2_gj_x = c2_fj_x;
  c2_gj_x = muDoubleScalarCos(c2_gj_x);
  c2_rc_a = c2_ej_x;
  c2_rc_b = c2_gj_x;
  c2_rc_y = c2_rc_a * c2_rc_b;
  c2_hj_x = c2_theta_2;
  c2_ij_x = c2_hj_x;
  c2_ij_x = muDoubleScalarSin(c2_ij_x);
  c2_jj_x = c2_theta_3;
  c2_kj_x = c2_jj_x;
  c2_kj_x = muDoubleScalarSin(c2_kj_x);
  c2_sc_a = c2_ij_x;
  c2_sc_b = c2_kj_x;
  c2_sc_y = c2_sc_a * c2_sc_b;
  c2_tc_a = c2_cj_x;
  c2_tc_b = c2_rc_y - c2_sc_y;
  c2_tc_y = c2_tc_a * c2_tc_b;
  c2_lj_x = c2_theta_4;
  c2_mj_x = c2_lj_x;
  c2_mj_x = muDoubleScalarSin(c2_mj_x);
  c2_nj_x = c2_theta_2;
  c2_oj_x = c2_nj_x;
  c2_oj_x = muDoubleScalarCos(c2_oj_x);
  c2_pj_x = c2_theta_3;
  c2_qj_x = c2_pj_x;
  c2_qj_x = muDoubleScalarSin(c2_qj_x);
  c2_uc_a = c2_oj_x;
  c2_uc_b = c2_qj_x;
  c2_uc_y = c2_uc_a * c2_uc_b;
  c2_rj_x = c2_theta_3;
  c2_sj_x = c2_rj_x;
  c2_sj_x = muDoubleScalarCos(c2_sj_x);
  c2_tj_x = c2_theta_2;
  c2_uj_x = c2_tj_x;
  c2_uj_x = muDoubleScalarSin(c2_uj_x);
  c2_vc_a = c2_sj_x;
  c2_vc_b = c2_uj_x;
  c2_vc_y = c2_vc_a * c2_vc_b;
  c2_wc_a = c2_mj_x;
  c2_wc_b = c2_uc_y + c2_vc_y;
  c2_wc_y = c2_wc_a * c2_wc_b;
  c2_vj_x = c2_theta_4;
  c2_wj_x = c2_vj_x;
  c2_wj_x = muDoubleScalarCos(c2_wj_x);
  c2_xj_x = c2_theta_2;
  c2_yj_x = c2_xj_x;
  c2_yj_x = muDoubleScalarCos(c2_yj_x);
  c2_ak_x = c2_theta_3;
  c2_bk_x = c2_ak_x;
  c2_bk_x = muDoubleScalarCos(c2_bk_x);
  c2_xc_a = c2_yj_x;
  c2_xc_b = c2_bk_x;
  c2_xc_y = c2_xc_a * c2_xc_b;
  c2_ck_x = c2_theta_2;
  c2_dk_x = c2_ck_x;
  c2_dk_x = muDoubleScalarSin(c2_dk_x);
  c2_ek_x = c2_theta_3;
  c2_fk_x = c2_ek_x;
  c2_fk_x = muDoubleScalarSin(c2_fk_x);
  c2_yc_a = c2_dk_x;
  c2_yc_b = c2_fk_x;
  c2_yc_y = c2_yc_a * c2_yc_b;
  c2_ad_a = c2_wj_x;
  c2_ad_b = c2_xc_y - c2_yc_y;
  c2_ad_y = c2_ad_a * c2_ad_b;
  c2_R4[0] = c2_db_y - c2_ib_y;
  c2_R4[3] = c2_ef_x;
  c2_R4[6] = c2_nb_y - c2_sb_y;
  c2_R4[1] = c2_xb_y - c2_dc_y;
  c2_R4[4] = -c2_mh_x;
  c2_R4[7] = c2_ic_y - c2_nc_y;
  c2_R4[2] = c2_qc_y + c2_tc_y;
  c2_R4[5] = 0.0;
  c2_R4[8] = c2_wc_y - c2_ad_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_gk_x = c2_theta_1;
  c2_hk_x = c2_gk_x;
  c2_hk_x = muDoubleScalarSin(c2_hk_x);
  c2_ik_x = c2_theta_5;
  c2_jk_x = c2_ik_x;
  c2_jk_x = muDoubleScalarSin(c2_jk_x);
  c2_bd_a = c2_hk_x;
  c2_bd_b = c2_jk_x;
  c2_bd_y = c2_bd_a * c2_bd_b;
  c2_kk_x = c2_theta_5;
  c2_lk_x = c2_kk_x;
  c2_lk_x = muDoubleScalarCos(c2_lk_x);
  c2_mk_x = c2_theta_4;
  c2_nk_x = c2_mk_x;
  c2_nk_x = muDoubleScalarCos(c2_nk_x);
  c2_ok_x = c2_theta_1;
  c2_pk_x = c2_ok_x;
  c2_pk_x = muDoubleScalarCos(c2_pk_x);
  c2_qk_x = c2_theta_2;
  c2_rk_x = c2_qk_x;
  c2_rk_x = muDoubleScalarSin(c2_rk_x);
  c2_cd_a = c2_pk_x;
  c2_cd_b = c2_rk_x;
  c2_cd_y = c2_cd_a * c2_cd_b;
  c2_sk_x = c2_theta_3;
  c2_tk_x = c2_sk_x;
  c2_tk_x = muDoubleScalarSin(c2_tk_x);
  c2_dd_a = c2_cd_y;
  c2_dd_b = c2_tk_x;
  c2_dd_y = c2_dd_a * c2_dd_b;
  c2_uk_x = c2_theta_1;
  c2_vk_x = c2_uk_x;
  c2_vk_x = muDoubleScalarCos(c2_vk_x);
  c2_wk_x = c2_theta_2;
  c2_xk_x = c2_wk_x;
  c2_xk_x = muDoubleScalarCos(c2_xk_x);
  c2_ed_a = c2_vk_x;
  c2_ed_b = c2_xk_x;
  c2_ed_y = c2_ed_a * c2_ed_b;
  c2_yk_x = c2_theta_3;
  c2_al_x = c2_yk_x;
  c2_al_x = muDoubleScalarCos(c2_al_x);
  c2_fd_a = c2_ed_y;
  c2_fd_b = c2_al_x;
  c2_fd_y = c2_fd_a * c2_fd_b;
  c2_gd_a = c2_nk_x;
  c2_gd_b = c2_dd_y - c2_fd_y;
  c2_gd_y = c2_gd_a * c2_gd_b;
  c2_bl_x = c2_theta_4;
  c2_cl_x = c2_bl_x;
  c2_cl_x = muDoubleScalarSin(c2_cl_x);
  c2_dl_x = c2_theta_1;
  c2_el_x = c2_dl_x;
  c2_el_x = muDoubleScalarCos(c2_el_x);
  c2_fl_x = c2_theta_2;
  c2_gl_x = c2_fl_x;
  c2_gl_x = muDoubleScalarCos(c2_gl_x);
  c2_hd_a = c2_el_x;
  c2_hd_b = c2_gl_x;
  c2_hd_y = c2_hd_a * c2_hd_b;
  c2_hl_x = c2_theta_3;
  c2_il_x = c2_hl_x;
  c2_il_x = muDoubleScalarSin(c2_il_x);
  c2_id_a = c2_hd_y;
  c2_id_b = c2_il_x;
  c2_id_y = c2_id_a * c2_id_b;
  c2_jl_x = c2_theta_1;
  c2_kl_x = c2_jl_x;
  c2_kl_x = muDoubleScalarCos(c2_kl_x);
  c2_ll_x = c2_theta_3;
  c2_ml_x = c2_ll_x;
  c2_ml_x = muDoubleScalarCos(c2_ml_x);
  c2_jd_a = c2_kl_x;
  c2_jd_b = c2_ml_x;
  c2_jd_y = c2_jd_a * c2_jd_b;
  c2_nl_x = c2_theta_2;
  c2_ol_x = c2_nl_x;
  c2_ol_x = muDoubleScalarSin(c2_ol_x);
  c2_kd_a = c2_jd_y;
  c2_kd_b = c2_ol_x;
  c2_kd_y = c2_kd_a * c2_kd_b;
  c2_ld_a = c2_cl_x;
  c2_ld_b = c2_id_y + c2_kd_y;
  c2_ld_y = c2_ld_a * c2_ld_b;
  c2_md_a = c2_lk_x;
  c2_md_b = c2_gd_y + c2_ld_y;
  c2_md_y = c2_md_a * c2_md_b;
  c2_pl_x = c2_theta_4;
  c2_ql_x = c2_pl_x;
  c2_ql_x = muDoubleScalarSin(c2_ql_x);
  c2_rl_x = c2_theta_1;
  c2_sl_x = c2_rl_x;
  c2_sl_x = muDoubleScalarCos(c2_sl_x);
  c2_tl_x = c2_theta_2;
  c2_ul_x = c2_tl_x;
  c2_ul_x = muDoubleScalarSin(c2_ul_x);
  c2_nd_a = c2_sl_x;
  c2_nd_b = c2_ul_x;
  c2_nd_y = c2_nd_a * c2_nd_b;
  c2_vl_x = c2_theta_3;
  c2_wl_x = c2_vl_x;
  c2_wl_x = muDoubleScalarSin(c2_wl_x);
  c2_od_a = c2_nd_y;
  c2_od_b = c2_wl_x;
  c2_od_y = c2_od_a * c2_od_b;
  c2_xl_x = c2_theta_1;
  c2_yl_x = c2_xl_x;
  c2_yl_x = muDoubleScalarCos(c2_yl_x);
  c2_am_x = c2_theta_2;
  c2_bm_x = c2_am_x;
  c2_bm_x = muDoubleScalarCos(c2_bm_x);
  c2_pd_a = c2_yl_x;
  c2_pd_b = c2_bm_x;
  c2_pd_y = c2_pd_a * c2_pd_b;
  c2_cm_x = c2_theta_3;
  c2_dm_x = c2_cm_x;
  c2_dm_x = muDoubleScalarCos(c2_dm_x);
  c2_qd_a = c2_pd_y;
  c2_qd_b = c2_dm_x;
  c2_qd_y = c2_qd_a * c2_qd_b;
  c2_rd_a = c2_ql_x;
  c2_rd_b = c2_od_y - c2_qd_y;
  c2_rd_y = c2_rd_a * c2_rd_b;
  c2_em_x = c2_theta_4;
  c2_fm_x = c2_em_x;
  c2_fm_x = muDoubleScalarCos(c2_fm_x);
  c2_gm_x = c2_theta_1;
  c2_hm_x = c2_gm_x;
  c2_hm_x = muDoubleScalarCos(c2_hm_x);
  c2_im_x = c2_theta_2;
  c2_jm_x = c2_im_x;
  c2_jm_x = muDoubleScalarCos(c2_jm_x);
  c2_sd_a = c2_hm_x;
  c2_sd_b = c2_jm_x;
  c2_sd_y = c2_sd_a * c2_sd_b;
  c2_km_x = c2_theta_3;
  c2_lm_x = c2_km_x;
  c2_lm_x = muDoubleScalarSin(c2_lm_x);
  c2_td_a = c2_sd_y;
  c2_td_b = c2_lm_x;
  c2_td_y = c2_td_a * c2_td_b;
  c2_mm_x = c2_theta_1;
  c2_nm_x = c2_mm_x;
  c2_nm_x = muDoubleScalarCos(c2_nm_x);
  c2_om_x = c2_theta_3;
  c2_pm_x = c2_om_x;
  c2_pm_x = muDoubleScalarCos(c2_pm_x);
  c2_ud_a = c2_nm_x;
  c2_ud_b = c2_pm_x;
  c2_ud_y = c2_ud_a * c2_ud_b;
  c2_qm_x = c2_theta_2;
  c2_rm_x = c2_qm_x;
  c2_rm_x = muDoubleScalarSin(c2_rm_x);
  c2_vd_a = c2_ud_y;
  c2_vd_b = c2_rm_x;
  c2_vd_y = c2_vd_a * c2_vd_b;
  c2_wd_a = c2_fm_x;
  c2_wd_b = c2_td_y + c2_vd_y;
  c2_wd_y = c2_wd_a * c2_wd_b;
  c2_sm_x = c2_theta_5;
  c2_tm_x = c2_sm_x;
  c2_tm_x = muDoubleScalarCos(c2_tm_x);
  c2_um_x = c2_theta_1;
  c2_vm_x = c2_um_x;
  c2_vm_x = muDoubleScalarSin(c2_vm_x);
  c2_xd_a = c2_tm_x;
  c2_xd_b = c2_vm_x;
  c2_xd_y = c2_xd_a * c2_xd_b;
  c2_wm_x = c2_theta_5;
  c2_xm_x = c2_wm_x;
  c2_xm_x = muDoubleScalarSin(c2_xm_x);
  c2_ym_x = c2_theta_4;
  c2_an_x = c2_ym_x;
  c2_an_x = muDoubleScalarCos(c2_an_x);
  c2_bn_x = c2_theta_1;
  c2_cn_x = c2_bn_x;
  c2_cn_x = muDoubleScalarCos(c2_cn_x);
  c2_dn_x = c2_theta_2;
  c2_en_x = c2_dn_x;
  c2_en_x = muDoubleScalarSin(c2_en_x);
  c2_yd_a = c2_cn_x;
  c2_yd_b = c2_en_x;
  c2_yd_y = c2_yd_a * c2_yd_b;
  c2_fn_x = c2_theta_3;
  c2_gn_x = c2_fn_x;
  c2_gn_x = muDoubleScalarSin(c2_gn_x);
  c2_ae_a = c2_yd_y;
  c2_ae_b = c2_gn_x;
  c2_ae_y = c2_ae_a * c2_ae_b;
  c2_hn_x = c2_theta_1;
  c2_in_x = c2_hn_x;
  c2_in_x = muDoubleScalarCos(c2_in_x);
  c2_jn_x = c2_theta_2;
  c2_kn_x = c2_jn_x;
  c2_kn_x = muDoubleScalarCos(c2_kn_x);
  c2_be_a = c2_in_x;
  c2_be_b = c2_kn_x;
  c2_be_y = c2_be_a * c2_be_b;
  c2_ln_x = c2_theta_3;
  c2_mn_x = c2_ln_x;
  c2_mn_x = muDoubleScalarCos(c2_mn_x);
  c2_ce_a = c2_be_y;
  c2_ce_b = c2_mn_x;
  c2_ce_y = c2_ce_a * c2_ce_b;
  c2_de_a = c2_an_x;
  c2_de_b = c2_ae_y - c2_ce_y;
  c2_de_y = c2_de_a * c2_de_b;
  c2_nn_x = c2_theta_4;
  c2_on_x = c2_nn_x;
  c2_on_x = muDoubleScalarSin(c2_on_x);
  c2_pn_x = c2_theta_1;
  c2_qn_x = c2_pn_x;
  c2_qn_x = muDoubleScalarCos(c2_qn_x);
  c2_rn_x = c2_theta_2;
  c2_sn_x = c2_rn_x;
  c2_sn_x = muDoubleScalarCos(c2_sn_x);
  c2_ee_a = c2_qn_x;
  c2_ee_b = c2_sn_x;
  c2_ee_y = c2_ee_a * c2_ee_b;
  c2_tn_x = c2_theta_3;
  c2_un_x = c2_tn_x;
  c2_un_x = muDoubleScalarSin(c2_un_x);
  c2_fe_a = c2_ee_y;
  c2_fe_b = c2_un_x;
  c2_fe_y = c2_fe_a * c2_fe_b;
  c2_vn_x = c2_theta_1;
  c2_wn_x = c2_vn_x;
  c2_wn_x = muDoubleScalarCos(c2_wn_x);
  c2_xn_x = c2_theta_3;
  c2_yn_x = c2_xn_x;
  c2_yn_x = muDoubleScalarCos(c2_yn_x);
  c2_ge_a = c2_wn_x;
  c2_ge_b = c2_yn_x;
  c2_ge_y = c2_ge_a * c2_ge_b;
  c2_ao_x = c2_theta_2;
  c2_bo_x = c2_ao_x;
  c2_bo_x = muDoubleScalarSin(c2_bo_x);
  c2_he_a = c2_ge_y;
  c2_he_b = c2_bo_x;
  c2_he_y = c2_he_a * c2_he_b;
  c2_ie_a = c2_on_x;
  c2_ie_b = c2_fe_y + c2_he_y;
  c2_ie_y = c2_ie_a * c2_ie_b;
  c2_je_a = c2_xm_x;
  c2_je_b = c2_de_y + c2_ie_y;
  c2_je_y = c2_je_a * c2_je_b;
  c2_co_x = c2_theta_1;
  c2_do_x = c2_co_x;
  c2_do_x = muDoubleScalarCos(c2_do_x);
  c2_eo_x = c2_theta_5;
  c2_fo_x = c2_eo_x;
  c2_fo_x = muDoubleScalarSin(c2_fo_x);
  c2_ke_a = -c2_do_x;
  c2_ke_b = c2_fo_x;
  c2_ke_y = c2_ke_a * c2_ke_b;
  c2_go_x = c2_theta_5;
  c2_ho_x = c2_go_x;
  c2_ho_x = muDoubleScalarCos(c2_ho_x);
  c2_io_x = c2_theta_4;
  c2_jo_x = c2_io_x;
  c2_jo_x = muDoubleScalarCos(c2_jo_x);
  c2_ko_x = c2_theta_1;
  c2_lo_x = c2_ko_x;
  c2_lo_x = muDoubleScalarSin(c2_lo_x);
  c2_mo_x = c2_theta_2;
  c2_no_x = c2_mo_x;
  c2_no_x = muDoubleScalarSin(c2_no_x);
  c2_le_a = c2_lo_x;
  c2_le_b = c2_no_x;
  c2_le_y = c2_le_a * c2_le_b;
  c2_oo_x = c2_theta_3;
  c2_po_x = c2_oo_x;
  c2_po_x = muDoubleScalarSin(c2_po_x);
  c2_me_a = c2_le_y;
  c2_me_b = c2_po_x;
  c2_me_y = c2_me_a * c2_me_b;
  c2_qo_x = c2_theta_2;
  c2_ro_x = c2_qo_x;
  c2_ro_x = muDoubleScalarCos(c2_ro_x);
  c2_so_x = c2_theta_3;
  c2_to_x = c2_so_x;
  c2_to_x = muDoubleScalarCos(c2_to_x);
  c2_ne_a = c2_ro_x;
  c2_ne_b = c2_to_x;
  c2_ne_y = c2_ne_a * c2_ne_b;
  c2_uo_x = c2_theta_1;
  c2_vo_x = c2_uo_x;
  c2_vo_x = muDoubleScalarSin(c2_vo_x);
  c2_oe_a = c2_ne_y;
  c2_oe_b = c2_vo_x;
  c2_oe_y = c2_oe_a * c2_oe_b;
  c2_pe_a = c2_jo_x;
  c2_pe_b = c2_me_y - c2_oe_y;
  c2_pe_y = c2_pe_a * c2_pe_b;
  c2_wo_x = c2_theta_4;
  c2_xo_x = c2_wo_x;
  c2_xo_x = muDoubleScalarSin(c2_xo_x);
  c2_yo_x = c2_theta_2;
  c2_ap_x = c2_yo_x;
  c2_ap_x = muDoubleScalarCos(c2_ap_x);
  c2_bp_x = c2_theta_1;
  c2_cp_x = c2_bp_x;
  c2_cp_x = muDoubleScalarSin(c2_cp_x);
  c2_qe_a = c2_ap_x;
  c2_qe_b = c2_cp_x;
  c2_qe_y = c2_qe_a * c2_qe_b;
  c2_dp_x = c2_theta_3;
  c2_ep_x = c2_dp_x;
  c2_ep_x = muDoubleScalarSin(c2_ep_x);
  c2_re_a = c2_qe_y;
  c2_re_b = c2_ep_x;
  c2_re_y = c2_re_a * c2_re_b;
  c2_fp_x = c2_theta_3;
  c2_gp_x = c2_fp_x;
  c2_gp_x = muDoubleScalarCos(c2_gp_x);
  c2_hp_x = c2_theta_1;
  c2_ip_x = c2_hp_x;
  c2_ip_x = muDoubleScalarSin(c2_ip_x);
  c2_se_a = c2_gp_x;
  c2_se_b = c2_ip_x;
  c2_se_y = c2_se_a * c2_se_b;
  c2_jp_x = c2_theta_2;
  c2_kp_x = c2_jp_x;
  c2_kp_x = muDoubleScalarSin(c2_kp_x);
  c2_te_a = c2_se_y;
  c2_te_b = c2_kp_x;
  c2_te_y = c2_te_a * c2_te_b;
  c2_ue_a = c2_xo_x;
  c2_ue_b = c2_re_y + c2_te_y;
  c2_ue_y = c2_ue_a * c2_ue_b;
  c2_ve_a = c2_ho_x;
  c2_ve_b = c2_pe_y + c2_ue_y;
  c2_ve_y = c2_ve_a * c2_ve_b;
  c2_lp_x = c2_theta_4;
  c2_mp_x = c2_lp_x;
  c2_mp_x = muDoubleScalarSin(c2_mp_x);
  c2_np_x = c2_theta_1;
  c2_op_x = c2_np_x;
  c2_op_x = muDoubleScalarSin(c2_op_x);
  c2_pp_x = c2_theta_2;
  c2_qp_x = c2_pp_x;
  c2_qp_x = muDoubleScalarSin(c2_qp_x);
  c2_we_a = c2_op_x;
  c2_we_b = c2_qp_x;
  c2_we_y = c2_we_a * c2_we_b;
  c2_rp_x = c2_theta_3;
  c2_sp_x = c2_rp_x;
  c2_sp_x = muDoubleScalarSin(c2_sp_x);
  c2_xe_a = c2_we_y;
  c2_xe_b = c2_sp_x;
  c2_xe_y = c2_xe_a * c2_xe_b;
  c2_tp_x = c2_theta_2;
  c2_up_x = c2_tp_x;
  c2_up_x = muDoubleScalarCos(c2_up_x);
  c2_vp_x = c2_theta_3;
  c2_wp_x = c2_vp_x;
  c2_wp_x = muDoubleScalarCos(c2_wp_x);
  c2_ye_a = c2_up_x;
  c2_ye_b = c2_wp_x;
  c2_ye_y = c2_ye_a * c2_ye_b;
  c2_xp_x = c2_theta_1;
  c2_yp_x = c2_xp_x;
  c2_yp_x = muDoubleScalarSin(c2_yp_x);
  c2_af_a = c2_ye_y;
  c2_af_b = c2_yp_x;
  c2_af_y = c2_af_a * c2_af_b;
  c2_bf_a = c2_mp_x;
  c2_bf_b = c2_xe_y - c2_af_y;
  c2_bf_y = c2_bf_a * c2_bf_b;
  c2_aq_x = c2_theta_4;
  c2_bq_x = c2_aq_x;
  c2_bq_x = muDoubleScalarCos(c2_bq_x);
  c2_cq_x = c2_theta_2;
  c2_dq_x = c2_cq_x;
  c2_dq_x = muDoubleScalarCos(c2_dq_x);
  c2_eq_x = c2_theta_1;
  c2_fq_x = c2_eq_x;
  c2_fq_x = muDoubleScalarSin(c2_fq_x);
  c2_cf_a = c2_dq_x;
  c2_cf_b = c2_fq_x;
  c2_cf_y = c2_cf_a * c2_cf_b;
  c2_gq_x = c2_theta_3;
  c2_hq_x = c2_gq_x;
  c2_hq_x = muDoubleScalarSin(c2_hq_x);
  c2_df_a = c2_cf_y;
  c2_df_b = c2_hq_x;
  c2_df_y = c2_df_a * c2_df_b;
  c2_iq_x = c2_theta_3;
  c2_jq_x = c2_iq_x;
  c2_jq_x = muDoubleScalarCos(c2_jq_x);
  c2_kq_x = c2_theta_1;
  c2_lq_x = c2_kq_x;
  c2_lq_x = muDoubleScalarSin(c2_lq_x);
  c2_ef_a = c2_jq_x;
  c2_ef_b = c2_lq_x;
  c2_ef_y = c2_ef_a * c2_ef_b;
  c2_mq_x = c2_theta_2;
  c2_nq_x = c2_mq_x;
  c2_nq_x = muDoubleScalarSin(c2_nq_x);
  c2_ff_a = c2_ef_y;
  c2_ff_b = c2_nq_x;
  c2_ff_y = c2_ff_a * c2_ff_b;
  c2_gf_a = c2_bq_x;
  c2_gf_b = c2_df_y + c2_ff_y;
  c2_gf_y = c2_gf_a * c2_gf_b;
  c2_oq_x = c2_theta_5;
  c2_pq_x = c2_oq_x;
  c2_pq_x = muDoubleScalarSin(c2_pq_x);
  c2_qq_x = c2_theta_4;
  c2_rq_x = c2_qq_x;
  c2_rq_x = muDoubleScalarCos(c2_rq_x);
  c2_sq_x = c2_theta_1;
  c2_tq_x = c2_sq_x;
  c2_tq_x = muDoubleScalarSin(c2_tq_x);
  c2_uq_x = c2_theta_2;
  c2_vq_x = c2_uq_x;
  c2_vq_x = muDoubleScalarSin(c2_vq_x);
  c2_hf_a = c2_tq_x;
  c2_hf_b = c2_vq_x;
  c2_hf_y = c2_hf_a * c2_hf_b;
  c2_wq_x = c2_theta_3;
  c2_xq_x = c2_wq_x;
  c2_xq_x = muDoubleScalarSin(c2_xq_x);
  c2_if_a = c2_hf_y;
  c2_if_b = c2_xq_x;
  c2_if_y = c2_if_a * c2_if_b;
  c2_yq_x = c2_theta_2;
  c2_ar_x = c2_yq_x;
  c2_ar_x = muDoubleScalarCos(c2_ar_x);
  c2_br_x = c2_theta_3;
  c2_cr_x = c2_br_x;
  c2_cr_x = muDoubleScalarCos(c2_cr_x);
  c2_jf_a = c2_ar_x;
  c2_jf_b = c2_cr_x;
  c2_jf_y = c2_jf_a * c2_jf_b;
  c2_dr_x = c2_theta_1;
  c2_er_x = c2_dr_x;
  c2_er_x = muDoubleScalarSin(c2_er_x);
  c2_kf_a = c2_jf_y;
  c2_kf_b = c2_er_x;
  c2_kf_y = c2_kf_a * c2_kf_b;
  c2_lf_a = c2_rq_x;
  c2_lf_b = c2_if_y - c2_kf_y;
  c2_lf_y = c2_lf_a * c2_lf_b;
  c2_fr_x = c2_theta_4;
  c2_gr_x = c2_fr_x;
  c2_gr_x = muDoubleScalarSin(c2_gr_x);
  c2_hr_x = c2_theta_2;
  c2_ir_x = c2_hr_x;
  c2_ir_x = muDoubleScalarCos(c2_ir_x);
  c2_jr_x = c2_theta_1;
  c2_kr_x = c2_jr_x;
  c2_kr_x = muDoubleScalarSin(c2_kr_x);
  c2_mf_a = c2_ir_x;
  c2_mf_b = c2_kr_x;
  c2_mf_y = c2_mf_a * c2_mf_b;
  c2_lr_x = c2_theta_3;
  c2_mr_x = c2_lr_x;
  c2_mr_x = muDoubleScalarSin(c2_mr_x);
  c2_nf_a = c2_mf_y;
  c2_nf_b = c2_mr_x;
  c2_nf_y = c2_nf_a * c2_nf_b;
  c2_nr_x = c2_theta_3;
  c2_or_x = c2_nr_x;
  c2_or_x = muDoubleScalarCos(c2_or_x);
  c2_pr_x = c2_theta_1;
  c2_qr_x = c2_pr_x;
  c2_qr_x = muDoubleScalarSin(c2_qr_x);
  c2_of_a = c2_or_x;
  c2_of_b = c2_qr_x;
  c2_of_y = c2_of_a * c2_of_b;
  c2_rr_x = c2_theta_2;
  c2_sr_x = c2_rr_x;
  c2_sr_x = muDoubleScalarSin(c2_sr_x);
  c2_pf_a = c2_of_y;
  c2_pf_b = c2_sr_x;
  c2_pf_y = c2_pf_a * c2_pf_b;
  c2_qf_a = c2_gr_x;
  c2_qf_b = c2_nf_y + c2_pf_y;
  c2_qf_y = c2_qf_a * c2_qf_b;
  c2_rf_a = c2_pq_x;
  c2_rf_b = c2_lf_y + c2_qf_y;
  c2_rf_y = c2_rf_a * c2_rf_b;
  c2_tr_x = c2_theta_1;
  c2_ur_x = c2_tr_x;
  c2_ur_x = muDoubleScalarCos(c2_ur_x);
  c2_vr_x = c2_theta_5;
  c2_wr_x = c2_vr_x;
  c2_wr_x = muDoubleScalarCos(c2_wr_x);
  c2_sf_a = c2_ur_x;
  c2_sf_b = c2_wr_x;
  c2_sf_y = c2_sf_a * c2_sf_b;
  c2_xr_x = c2_theta_5;
  c2_yr_x = c2_xr_x;
  c2_yr_x = muDoubleScalarCos(c2_yr_x);
  c2_as_x = c2_theta_4;
  c2_bs_x = c2_as_x;
  c2_bs_x = muDoubleScalarCos(c2_bs_x);
  c2_cs_x = c2_theta_2;
  c2_ds_x = c2_cs_x;
  c2_ds_x = muDoubleScalarCos(c2_ds_x);
  c2_es_x = c2_theta_3;
  c2_fs_x = c2_es_x;
  c2_fs_x = muDoubleScalarSin(c2_fs_x);
  c2_tf_a = c2_ds_x;
  c2_tf_b = c2_fs_x;
  c2_tf_y = c2_tf_a * c2_tf_b;
  c2_gs_x = c2_theta_3;
  c2_hs_x = c2_gs_x;
  c2_hs_x = muDoubleScalarCos(c2_hs_x);
  c2_is_x = c2_theta_2;
  c2_js_x = c2_is_x;
  c2_js_x = muDoubleScalarSin(c2_js_x);
  c2_uf_a = c2_hs_x;
  c2_uf_b = c2_js_x;
  c2_uf_y = c2_uf_a * c2_uf_b;
  c2_vf_a = c2_bs_x;
  c2_vf_b = c2_tf_y + c2_uf_y;
  c2_vf_y = c2_vf_a * c2_vf_b;
  c2_ks_x = c2_theta_4;
  c2_ls_x = c2_ks_x;
  c2_ls_x = muDoubleScalarSin(c2_ls_x);
  c2_ms_x = c2_theta_2;
  c2_ns_x = c2_ms_x;
  c2_ns_x = muDoubleScalarCos(c2_ns_x);
  c2_os_x = c2_theta_3;
  c2_ps_x = c2_os_x;
  c2_ps_x = muDoubleScalarCos(c2_ps_x);
  c2_wf_a = c2_ns_x;
  c2_wf_b = c2_ps_x;
  c2_wf_y = c2_wf_a * c2_wf_b;
  c2_qs_x = c2_theta_2;
  c2_rs_x = c2_qs_x;
  c2_rs_x = muDoubleScalarSin(c2_rs_x);
  c2_ss_x = c2_theta_3;
  c2_ts_x = c2_ss_x;
  c2_ts_x = muDoubleScalarSin(c2_ts_x);
  c2_xf_a = c2_rs_x;
  c2_xf_b = c2_ts_x;
  c2_xf_y = c2_xf_a * c2_xf_b;
  c2_yf_a = c2_ls_x;
  c2_yf_b = c2_wf_y - c2_xf_y;
  c2_yf_y = c2_yf_a * c2_yf_b;
  c2_ag_a = c2_yr_x;
  c2_ag_b = c2_vf_y + c2_yf_y;
  c2_ag_y = c2_ag_a * c2_ag_b;
  c2_us_x = c2_theta_4;
  c2_vs_x = c2_us_x;
  c2_vs_x = muDoubleScalarCos(c2_vs_x);
  c2_ws_x = c2_theta_2;
  c2_xs_x = c2_ws_x;
  c2_xs_x = muDoubleScalarCos(c2_xs_x);
  c2_ys_x = c2_theta_3;
  c2_at_x = c2_ys_x;
  c2_at_x = muDoubleScalarCos(c2_at_x);
  c2_bg_a = c2_xs_x;
  c2_bg_b = c2_at_x;
  c2_bg_y = c2_bg_a * c2_bg_b;
  c2_bt_x = c2_theta_2;
  c2_ct_x = c2_bt_x;
  c2_ct_x = muDoubleScalarSin(c2_ct_x);
  c2_dt_x = c2_theta_3;
  c2_et_x = c2_dt_x;
  c2_et_x = muDoubleScalarSin(c2_et_x);
  c2_cg_a = c2_ct_x;
  c2_cg_b = c2_et_x;
  c2_cg_y = c2_cg_a * c2_cg_b;
  c2_dg_a = c2_vs_x;
  c2_dg_b = c2_bg_y - c2_cg_y;
  c2_dg_y = c2_dg_a * c2_dg_b;
  c2_ft_x = c2_theta_4;
  c2_gt_x = c2_ft_x;
  c2_gt_x = muDoubleScalarSin(c2_gt_x);
  c2_ht_x = c2_theta_2;
  c2_it_x = c2_ht_x;
  c2_it_x = muDoubleScalarCos(c2_it_x);
  c2_jt_x = c2_theta_3;
  c2_kt_x = c2_jt_x;
  c2_kt_x = muDoubleScalarSin(c2_kt_x);
  c2_eg_a = c2_it_x;
  c2_eg_b = c2_kt_x;
  c2_eg_y = c2_eg_a * c2_eg_b;
  c2_lt_x = c2_theta_3;
  c2_mt_x = c2_lt_x;
  c2_mt_x = muDoubleScalarCos(c2_mt_x);
  c2_nt_x = c2_theta_2;
  c2_ot_x = c2_nt_x;
  c2_ot_x = muDoubleScalarSin(c2_ot_x);
  c2_fg_a = c2_mt_x;
  c2_fg_b = c2_ot_x;
  c2_fg_y = c2_fg_a * c2_fg_b;
  c2_gg_a = c2_gt_x;
  c2_gg_b = c2_eg_y + c2_fg_y;
  c2_gg_y = c2_gg_a * c2_gg_b;
  c2_pt_x = c2_theta_5;
  c2_qt_x = c2_pt_x;
  c2_qt_x = muDoubleScalarSin(c2_qt_x);
  c2_rt_x = c2_theta_4;
  c2_st_x = c2_rt_x;
  c2_st_x = muDoubleScalarCos(c2_st_x);
  c2_tt_x = c2_theta_2;
  c2_ut_x = c2_tt_x;
  c2_ut_x = muDoubleScalarCos(c2_ut_x);
  c2_vt_x = c2_theta_3;
  c2_wt_x = c2_vt_x;
  c2_wt_x = muDoubleScalarSin(c2_wt_x);
  c2_hg_a = c2_ut_x;
  c2_hg_b = c2_wt_x;
  c2_hg_y = c2_hg_a * c2_hg_b;
  c2_xt_x = c2_theta_3;
  c2_yt_x = c2_xt_x;
  c2_yt_x = muDoubleScalarCos(c2_yt_x);
  c2_au_x = c2_theta_2;
  c2_bu_x = c2_au_x;
  c2_bu_x = muDoubleScalarSin(c2_bu_x);
  c2_ig_a = c2_yt_x;
  c2_ig_b = c2_bu_x;
  c2_ig_y = c2_ig_a * c2_ig_b;
  c2_jg_a = c2_st_x;
  c2_jg_b = c2_hg_y + c2_ig_y;
  c2_jg_y = c2_jg_a * c2_jg_b;
  c2_cu_x = c2_theta_4;
  c2_du_x = c2_cu_x;
  c2_du_x = muDoubleScalarSin(c2_du_x);
  c2_eu_x = c2_theta_2;
  c2_fu_x = c2_eu_x;
  c2_fu_x = muDoubleScalarCos(c2_fu_x);
  c2_gu_x = c2_theta_3;
  c2_hu_x = c2_gu_x;
  c2_hu_x = muDoubleScalarCos(c2_hu_x);
  c2_kg_a = c2_fu_x;
  c2_kg_b = c2_hu_x;
  c2_kg_y = c2_kg_a * c2_kg_b;
  c2_iu_x = c2_theta_2;
  c2_ju_x = c2_iu_x;
  c2_ju_x = muDoubleScalarSin(c2_ju_x);
  c2_ku_x = c2_theta_3;
  c2_lu_x = c2_ku_x;
  c2_lu_x = muDoubleScalarSin(c2_lu_x);
  c2_lg_a = c2_ju_x;
  c2_lg_b = c2_lu_x;
  c2_lg_y = c2_lg_a * c2_lg_b;
  c2_mg_a = c2_du_x;
  c2_mg_b = c2_kg_y - c2_lg_y;
  c2_mg_y = c2_mg_a * c2_mg_b;
  c2_ng_a = -c2_qt_x;
  c2_ng_b = c2_jg_y + c2_mg_y;
  c2_ng_y = c2_ng_a * c2_ng_b;
  c2_R5[0] = c2_bd_y - c2_md_y;
  c2_R5[3] = c2_rd_y - c2_wd_y;
  c2_R5[6] = c2_xd_y + c2_je_y;
  c2_R5[1] = c2_ke_y - c2_ve_y;
  c2_R5[4] = c2_bf_y - c2_gf_y;
  c2_R5[7] = c2_rf_y - c2_sf_y;
  c2_R5[2] = c2_ag_y;
  c2_R5[5] = c2_dg_y - c2_gg_y;
  c2_R5[8] = c2_ng_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_mu_x = c2_theta_6;
  c2_nu_x = c2_mu_x;
  c2_nu_x = muDoubleScalarCos(c2_nu_x);
  c2_ou_x = c2_theta_1;
  c2_pu_x = c2_ou_x;
  c2_pu_x = muDoubleScalarSin(c2_pu_x);
  c2_qu_x = c2_theta_5;
  c2_ru_x = c2_qu_x;
  c2_ru_x = muDoubleScalarSin(c2_ru_x);
  c2_og_a = c2_pu_x;
  c2_og_b = c2_ru_x;
  c2_og_y = c2_og_a * c2_og_b;
  c2_su_x = c2_theta_5;
  c2_tu_x = c2_su_x;
  c2_tu_x = muDoubleScalarCos(c2_tu_x);
  c2_uu_x = c2_theta_4;
  c2_vu_x = c2_uu_x;
  c2_vu_x = muDoubleScalarCos(c2_vu_x);
  c2_wu_x = c2_theta_1;
  c2_xu_x = c2_wu_x;
  c2_xu_x = muDoubleScalarCos(c2_xu_x);
  c2_yu_x = c2_theta_2;
  c2_av_x = c2_yu_x;
  c2_av_x = muDoubleScalarSin(c2_av_x);
  c2_pg_a = c2_xu_x;
  c2_pg_b = c2_av_x;
  c2_pg_y = c2_pg_a * c2_pg_b;
  c2_bv_x = c2_theta_3;
  c2_cv_x = c2_bv_x;
  c2_cv_x = muDoubleScalarSin(c2_cv_x);
  c2_qg_a = c2_pg_y;
  c2_qg_b = c2_cv_x;
  c2_qg_y = c2_qg_a * c2_qg_b;
  c2_dv_x = c2_theta_1;
  c2_ev_x = c2_dv_x;
  c2_ev_x = muDoubleScalarCos(c2_ev_x);
  c2_fv_x = c2_theta_2;
  c2_gv_x = c2_fv_x;
  c2_gv_x = muDoubleScalarCos(c2_gv_x);
  c2_rg_a = c2_ev_x;
  c2_rg_b = c2_gv_x;
  c2_rg_y = c2_rg_a * c2_rg_b;
  c2_hv_x = c2_theta_3;
  c2_iv_x = c2_hv_x;
  c2_iv_x = muDoubleScalarCos(c2_iv_x);
  c2_sg_a = c2_rg_y;
  c2_sg_b = c2_iv_x;
  c2_sg_y = c2_sg_a * c2_sg_b;
  c2_tg_a = c2_vu_x;
  c2_tg_b = c2_qg_y - c2_sg_y;
  c2_tg_y = c2_tg_a * c2_tg_b;
  c2_jv_x = c2_theta_4;
  c2_kv_x = c2_jv_x;
  c2_kv_x = muDoubleScalarSin(c2_kv_x);
  c2_lv_x = c2_theta_1;
  c2_mv_x = c2_lv_x;
  c2_mv_x = muDoubleScalarCos(c2_mv_x);
  c2_nv_x = c2_theta_2;
  c2_ov_x = c2_nv_x;
  c2_ov_x = muDoubleScalarCos(c2_ov_x);
  c2_ug_a = c2_mv_x;
  c2_ug_b = c2_ov_x;
  c2_ug_y = c2_ug_a * c2_ug_b;
  c2_pv_x = c2_theta_3;
  c2_qv_x = c2_pv_x;
  c2_qv_x = muDoubleScalarSin(c2_qv_x);
  c2_vg_a = c2_ug_y;
  c2_vg_b = c2_qv_x;
  c2_vg_y = c2_vg_a * c2_vg_b;
  c2_rv_x = c2_theta_1;
  c2_sv_x = c2_rv_x;
  c2_sv_x = muDoubleScalarCos(c2_sv_x);
  c2_tv_x = c2_theta_3;
  c2_uv_x = c2_tv_x;
  c2_uv_x = muDoubleScalarCos(c2_uv_x);
  c2_wg_a = c2_sv_x;
  c2_wg_b = c2_uv_x;
  c2_wg_y = c2_wg_a * c2_wg_b;
  c2_vv_x = c2_theta_2;
  c2_wv_x = c2_vv_x;
  c2_wv_x = muDoubleScalarSin(c2_wv_x);
  c2_xg_a = c2_wg_y;
  c2_xg_b = c2_wv_x;
  c2_xg_y = c2_xg_a * c2_xg_b;
  c2_yg_a = c2_kv_x;
  c2_yg_b = c2_vg_y + c2_xg_y;
  c2_yg_y = c2_yg_a * c2_yg_b;
  c2_ah_a = c2_tu_x;
  c2_ah_b = c2_tg_y + c2_yg_y;
  c2_ah_y = c2_ah_a * c2_ah_b;
  c2_bh_a = c2_nu_x;
  c2_bh_b = c2_og_y - c2_ah_y;
  c2_bh_y = c2_bh_a * c2_bh_b;
  c2_xv_x = c2_theta_6;
  c2_yv_x = c2_xv_x;
  c2_yv_x = muDoubleScalarSin(c2_yv_x);
  c2_aw_x = c2_theta_4;
  c2_bw_x = c2_aw_x;
  c2_bw_x = muDoubleScalarCos(c2_bw_x);
  c2_cw_x = c2_theta_1;
  c2_dw_x = c2_cw_x;
  c2_dw_x = muDoubleScalarCos(c2_dw_x);
  c2_ew_x = c2_theta_2;
  c2_fw_x = c2_ew_x;
  c2_fw_x = muDoubleScalarCos(c2_fw_x);
  c2_ch_a = c2_dw_x;
  c2_ch_b = c2_fw_x;
  c2_ch_y = c2_ch_a * c2_ch_b;
  c2_gw_x = c2_theta_3;
  c2_hw_x = c2_gw_x;
  c2_hw_x = muDoubleScalarSin(c2_hw_x);
  c2_dh_a = c2_ch_y;
  c2_dh_b = c2_hw_x;
  c2_dh_y = c2_dh_a * c2_dh_b;
  c2_iw_x = c2_theta_1;
  c2_jw_x = c2_iw_x;
  c2_jw_x = muDoubleScalarCos(c2_jw_x);
  c2_kw_x = c2_theta_3;
  c2_lw_x = c2_kw_x;
  c2_lw_x = muDoubleScalarCos(c2_lw_x);
  c2_eh_a = c2_jw_x;
  c2_eh_b = c2_lw_x;
  c2_eh_y = c2_eh_a * c2_eh_b;
  c2_mw_x = c2_theta_2;
  c2_nw_x = c2_mw_x;
  c2_nw_x = muDoubleScalarSin(c2_nw_x);
  c2_fh_a = c2_eh_y;
  c2_fh_b = c2_nw_x;
  c2_fh_y = c2_fh_a * c2_fh_b;
  c2_gh_a = c2_bw_x;
  c2_gh_b = c2_dh_y + c2_fh_y;
  c2_gh_y = c2_gh_a * c2_gh_b;
  c2_ow_x = c2_theta_4;
  c2_pw_x = c2_ow_x;
  c2_pw_x = muDoubleScalarSin(c2_pw_x);
  c2_qw_x = c2_theta_1;
  c2_rw_x = c2_qw_x;
  c2_rw_x = muDoubleScalarCos(c2_rw_x);
  c2_sw_x = c2_theta_2;
  c2_tw_x = c2_sw_x;
  c2_tw_x = muDoubleScalarSin(c2_tw_x);
  c2_hh_a = c2_rw_x;
  c2_hh_b = c2_tw_x;
  c2_hh_y = c2_hh_a * c2_hh_b;
  c2_uw_x = c2_theta_3;
  c2_vw_x = c2_uw_x;
  c2_vw_x = muDoubleScalarSin(c2_vw_x);
  c2_ih_a = c2_hh_y;
  c2_ih_b = c2_vw_x;
  c2_ih_y = c2_ih_a * c2_ih_b;
  c2_ww_x = c2_theta_1;
  c2_xw_x = c2_ww_x;
  c2_xw_x = muDoubleScalarCos(c2_xw_x);
  c2_yw_x = c2_theta_2;
  c2_ax_x = c2_yw_x;
  c2_ax_x = muDoubleScalarCos(c2_ax_x);
  c2_jh_a = c2_xw_x;
  c2_jh_b = c2_ax_x;
  c2_jh_y = c2_jh_a * c2_jh_b;
  c2_bx_x = c2_theta_3;
  c2_cx_x = c2_bx_x;
  c2_cx_x = muDoubleScalarCos(c2_cx_x);
  c2_kh_a = c2_jh_y;
  c2_kh_b = c2_cx_x;
  c2_kh_y = c2_kh_a * c2_kh_b;
  c2_lh_a = c2_pw_x;
  c2_lh_b = c2_ih_y - c2_kh_y;
  c2_lh_y = c2_lh_a * c2_lh_b;
  c2_mh_a = c2_yv_x;
  c2_mh_b = c2_gh_y - c2_lh_y;
  c2_mh_y = c2_mh_a * c2_mh_b;
  c2_dx_x = c2_theta_6;
  c2_ex_x = c2_dx_x;
  c2_ex_x = muDoubleScalarSin(c2_ex_x);
  c2_fx_x = c2_theta_1;
  c2_gx_x = c2_fx_x;
  c2_gx_x = muDoubleScalarSin(c2_gx_x);
  c2_hx_x = c2_theta_5;
  c2_ix_x = c2_hx_x;
  c2_ix_x = muDoubleScalarSin(c2_ix_x);
  c2_nh_a = c2_gx_x;
  c2_nh_b = c2_ix_x;
  c2_nh_y = c2_nh_a * c2_nh_b;
  c2_jx_x = c2_theta_5;
  c2_kx_x = c2_jx_x;
  c2_kx_x = muDoubleScalarCos(c2_kx_x);
  c2_lx_x = c2_theta_4;
  c2_mx_x = c2_lx_x;
  c2_mx_x = muDoubleScalarCos(c2_mx_x);
  c2_nx_x = c2_theta_1;
  c2_ox_x = c2_nx_x;
  c2_ox_x = muDoubleScalarCos(c2_ox_x);
  c2_px_x = c2_theta_2;
  c2_qx_x = c2_px_x;
  c2_qx_x = muDoubleScalarSin(c2_qx_x);
  c2_oh_a = c2_ox_x;
  c2_oh_b = c2_qx_x;
  c2_oh_y = c2_oh_a * c2_oh_b;
  c2_rx_x = c2_theta_3;
  c2_sx_x = c2_rx_x;
  c2_sx_x = muDoubleScalarSin(c2_sx_x);
  c2_ph_a = c2_oh_y;
  c2_ph_b = c2_sx_x;
  c2_ph_y = c2_ph_a * c2_ph_b;
  c2_tx_x = c2_theta_1;
  c2_ux_x = c2_tx_x;
  c2_ux_x = muDoubleScalarCos(c2_ux_x);
  c2_vx_x = c2_theta_2;
  c2_wx_x = c2_vx_x;
  c2_wx_x = muDoubleScalarCos(c2_wx_x);
  c2_qh_a = c2_ux_x;
  c2_qh_b = c2_wx_x;
  c2_qh_y = c2_qh_a * c2_qh_b;
  c2_xx_x = c2_theta_3;
  c2_yx_x = c2_xx_x;
  c2_yx_x = muDoubleScalarCos(c2_yx_x);
  c2_rh_a = c2_qh_y;
  c2_rh_b = c2_yx_x;
  c2_rh_y = c2_rh_a * c2_rh_b;
  c2_sh_a = c2_mx_x;
  c2_sh_b = c2_ph_y - c2_rh_y;
  c2_sh_y = c2_sh_a * c2_sh_b;
  c2_ay_x = c2_theta_4;
  c2_by_x = c2_ay_x;
  c2_by_x = muDoubleScalarSin(c2_by_x);
  c2_cy_x = c2_theta_1;
  c2_dy_x = c2_cy_x;
  c2_dy_x = muDoubleScalarCos(c2_dy_x);
  c2_ey_x = c2_theta_2;
  c2_fy_x = c2_ey_x;
  c2_fy_x = muDoubleScalarCos(c2_fy_x);
  c2_th_a = c2_dy_x;
  c2_th_b = c2_fy_x;
  c2_th_y = c2_th_a * c2_th_b;
  c2_gy_x = c2_theta_3;
  c2_hy_x = c2_gy_x;
  c2_hy_x = muDoubleScalarSin(c2_hy_x);
  c2_uh_a = c2_th_y;
  c2_uh_b = c2_hy_x;
  c2_uh_y = c2_uh_a * c2_uh_b;
  c2_iy_x = c2_theta_1;
  c2_jy_x = c2_iy_x;
  c2_jy_x = muDoubleScalarCos(c2_jy_x);
  c2_ky_x = c2_theta_3;
  c2_ly_x = c2_ky_x;
  c2_ly_x = muDoubleScalarCos(c2_ly_x);
  c2_vh_a = c2_jy_x;
  c2_vh_b = c2_ly_x;
  c2_vh_y = c2_vh_a * c2_vh_b;
  c2_my_x = c2_theta_2;
  c2_ny_x = c2_my_x;
  c2_ny_x = muDoubleScalarSin(c2_ny_x);
  c2_wh_a = c2_vh_y;
  c2_wh_b = c2_ny_x;
  c2_wh_y = c2_wh_a * c2_wh_b;
  c2_xh_a = c2_by_x;
  c2_xh_b = c2_uh_y + c2_wh_y;
  c2_xh_y = c2_xh_a * c2_xh_b;
  c2_yh_a = c2_kx_x;
  c2_yh_b = c2_sh_y + c2_xh_y;
  c2_yh_y = c2_yh_a * c2_yh_b;
  c2_ai_a = -c2_ex_x;
  c2_ai_b = c2_nh_y - c2_yh_y;
  c2_ai_y = c2_ai_a * c2_ai_b;
  c2_oy_x = c2_theta_6;
  c2_py_x = c2_oy_x;
  c2_py_x = muDoubleScalarCos(c2_py_x);
  c2_qy_x = c2_theta_4;
  c2_ry_x = c2_qy_x;
  c2_ry_x = muDoubleScalarCos(c2_ry_x);
  c2_sy_x = c2_theta_1;
  c2_ty_x = c2_sy_x;
  c2_ty_x = muDoubleScalarCos(c2_ty_x);
  c2_uy_x = c2_theta_2;
  c2_vy_x = c2_uy_x;
  c2_vy_x = muDoubleScalarCos(c2_vy_x);
  c2_bi_a = c2_ty_x;
  c2_bi_b = c2_vy_x;
  c2_bi_y = c2_bi_a * c2_bi_b;
  c2_wy_x = c2_theta_3;
  c2_xy_x = c2_wy_x;
  c2_xy_x = muDoubleScalarSin(c2_xy_x);
  c2_ci_a = c2_bi_y;
  c2_ci_b = c2_xy_x;
  c2_ci_y = c2_ci_a * c2_ci_b;
  c2_yy_x = c2_theta_1;
  c2_aab_x = c2_yy_x;
  c2_aab_x = muDoubleScalarCos(c2_aab_x);
  c2_bab_x = c2_theta_3;
  c2_cab_x = c2_bab_x;
  c2_cab_x = muDoubleScalarCos(c2_cab_x);
  c2_di_a = c2_aab_x;
  c2_di_b = c2_cab_x;
  c2_di_y = c2_di_a * c2_di_b;
  c2_dab_x = c2_theta_2;
  c2_eab_x = c2_dab_x;
  c2_eab_x = muDoubleScalarSin(c2_eab_x);
  c2_ei_a = c2_di_y;
  c2_ei_b = c2_eab_x;
  c2_ei_y = c2_ei_a * c2_ei_b;
  c2_fi_a = c2_ry_x;
  c2_fi_b = c2_ci_y + c2_ei_y;
  c2_fi_y = c2_fi_a * c2_fi_b;
  c2_fab_x = c2_theta_4;
  c2_gab_x = c2_fab_x;
  c2_gab_x = muDoubleScalarSin(c2_gab_x);
  c2_hab_x = c2_theta_1;
  c2_iab_x = c2_hab_x;
  c2_iab_x = muDoubleScalarCos(c2_iab_x);
  c2_jab_x = c2_theta_2;
  c2_kab_x = c2_jab_x;
  c2_kab_x = muDoubleScalarSin(c2_kab_x);
  c2_gi_a = c2_iab_x;
  c2_gi_b = c2_kab_x;
  c2_gi_y = c2_gi_a * c2_gi_b;
  c2_lab_x = c2_theta_3;
  c2_mab_x = c2_lab_x;
  c2_mab_x = muDoubleScalarSin(c2_mab_x);
  c2_hi_a = c2_gi_y;
  c2_hi_b = c2_mab_x;
  c2_hi_y = c2_hi_a * c2_hi_b;
  c2_nab_x = c2_theta_1;
  c2_oab_x = c2_nab_x;
  c2_oab_x = muDoubleScalarCos(c2_oab_x);
  c2_pab_x = c2_theta_2;
  c2_qab_x = c2_pab_x;
  c2_qab_x = muDoubleScalarCos(c2_qab_x);
  c2_ii_a = c2_oab_x;
  c2_ii_b = c2_qab_x;
  c2_ii_y = c2_ii_a * c2_ii_b;
  c2_rab_x = c2_theta_3;
  c2_sab_x = c2_rab_x;
  c2_sab_x = muDoubleScalarCos(c2_sab_x);
  c2_ji_a = c2_ii_y;
  c2_ji_b = c2_sab_x;
  c2_ji_y = c2_ji_a * c2_ji_b;
  c2_ki_a = c2_gab_x;
  c2_ki_b = c2_hi_y - c2_ji_y;
  c2_ki_y = c2_ki_a * c2_ki_b;
  c2_li_a = c2_py_x;
  c2_li_b = c2_fi_y - c2_ki_y;
  c2_li_y = c2_li_a * c2_li_b;
  c2_tab_x = c2_theta_5;
  c2_uab_x = c2_tab_x;
  c2_uab_x = muDoubleScalarCos(c2_uab_x);
  c2_vab_x = c2_theta_1;
  c2_wab_x = c2_vab_x;
  c2_wab_x = muDoubleScalarSin(c2_wab_x);
  c2_mi_a = c2_uab_x;
  c2_mi_b = c2_wab_x;
  c2_mi_y = c2_mi_a * c2_mi_b;
  c2_xab_x = c2_theta_5;
  c2_yab_x = c2_xab_x;
  c2_yab_x = muDoubleScalarSin(c2_yab_x);
  c2_abb_x = c2_theta_4;
  c2_bbb_x = c2_abb_x;
  c2_bbb_x = muDoubleScalarCos(c2_bbb_x);
  c2_cbb_x = c2_theta_1;
  c2_dbb_x = c2_cbb_x;
  c2_dbb_x = muDoubleScalarCos(c2_dbb_x);
  c2_ebb_x = c2_theta_2;
  c2_fbb_x = c2_ebb_x;
  c2_fbb_x = muDoubleScalarSin(c2_fbb_x);
  c2_ni_a = c2_dbb_x;
  c2_ni_b = c2_fbb_x;
  c2_ni_y = c2_ni_a * c2_ni_b;
  c2_gbb_x = c2_theta_3;
  c2_hbb_x = c2_gbb_x;
  c2_hbb_x = muDoubleScalarSin(c2_hbb_x);
  c2_oi_a = c2_ni_y;
  c2_oi_b = c2_hbb_x;
  c2_oi_y = c2_oi_a * c2_oi_b;
  c2_ibb_x = c2_theta_1;
  c2_jbb_x = c2_ibb_x;
  c2_jbb_x = muDoubleScalarCos(c2_jbb_x);
  c2_kbb_x = c2_theta_2;
  c2_lbb_x = c2_kbb_x;
  c2_lbb_x = muDoubleScalarCos(c2_lbb_x);
  c2_pi_a = c2_jbb_x;
  c2_pi_b = c2_lbb_x;
  c2_pi_y = c2_pi_a * c2_pi_b;
  c2_mbb_x = c2_theta_3;
  c2_nbb_x = c2_mbb_x;
  c2_nbb_x = muDoubleScalarCos(c2_nbb_x);
  c2_qi_a = c2_pi_y;
  c2_qi_b = c2_nbb_x;
  c2_qi_y = c2_qi_a * c2_qi_b;
  c2_ri_a = c2_bbb_x;
  c2_ri_b = c2_oi_y - c2_qi_y;
  c2_ri_y = c2_ri_a * c2_ri_b;
  c2_obb_x = c2_theta_4;
  c2_pbb_x = c2_obb_x;
  c2_pbb_x = muDoubleScalarSin(c2_pbb_x);
  c2_qbb_x = c2_theta_1;
  c2_rbb_x = c2_qbb_x;
  c2_rbb_x = muDoubleScalarCos(c2_rbb_x);
  c2_sbb_x = c2_theta_2;
  c2_tbb_x = c2_sbb_x;
  c2_tbb_x = muDoubleScalarCos(c2_tbb_x);
  c2_si_a = c2_rbb_x;
  c2_si_b = c2_tbb_x;
  c2_si_y = c2_si_a * c2_si_b;
  c2_ubb_x = c2_theta_3;
  c2_vbb_x = c2_ubb_x;
  c2_vbb_x = muDoubleScalarSin(c2_vbb_x);
  c2_ti_a = c2_si_y;
  c2_ti_b = c2_vbb_x;
  c2_ti_y = c2_ti_a * c2_ti_b;
  c2_wbb_x = c2_theta_1;
  c2_xbb_x = c2_wbb_x;
  c2_xbb_x = muDoubleScalarCos(c2_xbb_x);
  c2_ybb_x = c2_theta_3;
  c2_acb_x = c2_ybb_x;
  c2_acb_x = muDoubleScalarCos(c2_acb_x);
  c2_ui_a = c2_xbb_x;
  c2_ui_b = c2_acb_x;
  c2_ui_y = c2_ui_a * c2_ui_b;
  c2_bcb_x = c2_theta_2;
  c2_ccb_x = c2_bcb_x;
  c2_ccb_x = muDoubleScalarSin(c2_ccb_x);
  c2_vi_a = c2_ui_y;
  c2_vi_b = c2_ccb_x;
  c2_vi_y = c2_vi_a * c2_vi_b;
  c2_wi_a = c2_pbb_x;
  c2_wi_b = c2_ti_y + c2_vi_y;
  c2_wi_y = c2_wi_a * c2_wi_b;
  c2_xi_a = c2_yab_x;
  c2_xi_b = c2_ri_y + c2_wi_y;
  c2_xi_y = c2_xi_a * c2_xi_b;
  c2_dcb_x = c2_theta_6;
  c2_ecb_x = c2_dcb_x;
  c2_ecb_x = muDoubleScalarCos(c2_ecb_x);
  c2_fcb_x = c2_theta_1;
  c2_gcb_x = c2_fcb_x;
  c2_gcb_x = muDoubleScalarCos(c2_gcb_x);
  c2_hcb_x = c2_theta_5;
  c2_icb_x = c2_hcb_x;
  c2_icb_x = muDoubleScalarSin(c2_icb_x);
  c2_yi_a = c2_gcb_x;
  c2_yi_b = c2_icb_x;
  c2_yi_y = c2_yi_a * c2_yi_b;
  c2_jcb_x = c2_theta_5;
  c2_kcb_x = c2_jcb_x;
  c2_kcb_x = muDoubleScalarCos(c2_kcb_x);
  c2_lcb_x = c2_theta_4;
  c2_mcb_x = c2_lcb_x;
  c2_mcb_x = muDoubleScalarCos(c2_mcb_x);
  c2_ncb_x = c2_theta_1;
  c2_ocb_x = c2_ncb_x;
  c2_ocb_x = muDoubleScalarSin(c2_ocb_x);
  c2_pcb_x = c2_theta_2;
  c2_qcb_x = c2_pcb_x;
  c2_qcb_x = muDoubleScalarSin(c2_qcb_x);
  c2_aj_a = c2_ocb_x;
  c2_aj_b = c2_qcb_x;
  c2_aj_y = c2_aj_a * c2_aj_b;
  c2_rcb_x = c2_theta_3;
  c2_scb_x = c2_rcb_x;
  c2_scb_x = muDoubleScalarSin(c2_scb_x);
  c2_bj_a = c2_aj_y;
  c2_bj_b = c2_scb_x;
  c2_bj_y = c2_bj_a * c2_bj_b;
  c2_tcb_x = c2_theta_2;
  c2_ucb_x = c2_tcb_x;
  c2_ucb_x = muDoubleScalarCos(c2_ucb_x);
  c2_vcb_x = c2_theta_3;
  c2_wcb_x = c2_vcb_x;
  c2_wcb_x = muDoubleScalarCos(c2_wcb_x);
  c2_cj_a = c2_ucb_x;
  c2_cj_b = c2_wcb_x;
  c2_cj_y = c2_cj_a * c2_cj_b;
  c2_xcb_x = c2_theta_1;
  c2_ycb_x = c2_xcb_x;
  c2_ycb_x = muDoubleScalarSin(c2_ycb_x);
  c2_dj_a = c2_cj_y;
  c2_dj_b = c2_ycb_x;
  c2_dj_y = c2_dj_a * c2_dj_b;
  c2_ej_a = c2_mcb_x;
  c2_ej_b = c2_bj_y - c2_dj_y;
  c2_ej_y = c2_ej_a * c2_ej_b;
  c2_adb_x = c2_theta_4;
  c2_bdb_x = c2_adb_x;
  c2_bdb_x = muDoubleScalarSin(c2_bdb_x);
  c2_cdb_x = c2_theta_2;
  c2_ddb_x = c2_cdb_x;
  c2_ddb_x = muDoubleScalarCos(c2_ddb_x);
  c2_edb_x = c2_theta_1;
  c2_fdb_x = c2_edb_x;
  c2_fdb_x = muDoubleScalarSin(c2_fdb_x);
  c2_fj_a = c2_ddb_x;
  c2_fj_b = c2_fdb_x;
  c2_fj_y = c2_fj_a * c2_fj_b;
  c2_gdb_x = c2_theta_3;
  c2_hdb_x = c2_gdb_x;
  c2_hdb_x = muDoubleScalarSin(c2_hdb_x);
  c2_gj_a = c2_fj_y;
  c2_gj_b = c2_hdb_x;
  c2_gj_y = c2_gj_a * c2_gj_b;
  c2_idb_x = c2_theta_3;
  c2_jdb_x = c2_idb_x;
  c2_jdb_x = muDoubleScalarCos(c2_jdb_x);
  c2_kdb_x = c2_theta_1;
  c2_ldb_x = c2_kdb_x;
  c2_ldb_x = muDoubleScalarSin(c2_ldb_x);
  c2_hj_a = c2_jdb_x;
  c2_hj_b = c2_ldb_x;
  c2_hj_y = c2_hj_a * c2_hj_b;
  c2_mdb_x = c2_theta_2;
  c2_ndb_x = c2_mdb_x;
  c2_ndb_x = muDoubleScalarSin(c2_ndb_x);
  c2_ij_a = c2_hj_y;
  c2_ij_b = c2_ndb_x;
  c2_ij_y = c2_ij_a * c2_ij_b;
  c2_jj_a = c2_bdb_x;
  c2_jj_b = c2_gj_y + c2_ij_y;
  c2_jj_y = c2_jj_a * c2_jj_b;
  c2_kj_a = c2_kcb_x;
  c2_kj_b = c2_ej_y + c2_jj_y;
  c2_kj_y = c2_kj_a * c2_kj_b;
  c2_lj_a = -c2_ecb_x;
  c2_lj_b = c2_yi_y + c2_kj_y;
  c2_lj_y = c2_lj_a * c2_lj_b;
  c2_odb_x = c2_theta_6;
  c2_pdb_x = c2_odb_x;
  c2_pdb_x = muDoubleScalarSin(c2_pdb_x);
  c2_qdb_x = c2_theta_4;
  c2_rdb_x = c2_qdb_x;
  c2_rdb_x = muDoubleScalarCos(c2_rdb_x);
  c2_sdb_x = c2_theta_2;
  c2_tdb_x = c2_sdb_x;
  c2_tdb_x = muDoubleScalarCos(c2_tdb_x);
  c2_udb_x = c2_theta_1;
  c2_vdb_x = c2_udb_x;
  c2_vdb_x = muDoubleScalarSin(c2_vdb_x);
  c2_mj_a = c2_tdb_x;
  c2_mj_b = c2_vdb_x;
  c2_mj_y = c2_mj_a * c2_mj_b;
  c2_wdb_x = c2_theta_3;
  c2_xdb_x = c2_wdb_x;
  c2_xdb_x = muDoubleScalarSin(c2_xdb_x);
  c2_nj_a = c2_mj_y;
  c2_nj_b = c2_xdb_x;
  c2_nj_y = c2_nj_a * c2_nj_b;
  c2_ydb_x = c2_theta_3;
  c2_aeb_x = c2_ydb_x;
  c2_aeb_x = muDoubleScalarCos(c2_aeb_x);
  c2_beb_x = c2_theta_1;
  c2_ceb_x = c2_beb_x;
  c2_ceb_x = muDoubleScalarSin(c2_ceb_x);
  c2_oj_a = c2_aeb_x;
  c2_oj_b = c2_ceb_x;
  c2_oj_y = c2_oj_a * c2_oj_b;
  c2_deb_x = c2_theta_2;
  c2_eeb_x = c2_deb_x;
  c2_eeb_x = muDoubleScalarSin(c2_eeb_x);
  c2_pj_a = c2_oj_y;
  c2_pj_b = c2_eeb_x;
  c2_pj_y = c2_pj_a * c2_pj_b;
  c2_qj_a = c2_rdb_x;
  c2_qj_b = c2_nj_y + c2_pj_y;
  c2_qj_y = c2_qj_a * c2_qj_b;
  c2_feb_x = c2_theta_4;
  c2_geb_x = c2_feb_x;
  c2_geb_x = muDoubleScalarSin(c2_geb_x);
  c2_heb_x = c2_theta_1;
  c2_ieb_x = c2_heb_x;
  c2_ieb_x = muDoubleScalarSin(c2_ieb_x);
  c2_jeb_x = c2_theta_2;
  c2_keb_x = c2_jeb_x;
  c2_keb_x = muDoubleScalarSin(c2_keb_x);
  c2_rj_a = c2_ieb_x;
  c2_rj_b = c2_keb_x;
  c2_rj_y = c2_rj_a * c2_rj_b;
  c2_leb_x = c2_theta_3;
  c2_meb_x = c2_leb_x;
  c2_meb_x = muDoubleScalarSin(c2_meb_x);
  c2_sj_a = c2_rj_y;
  c2_sj_b = c2_meb_x;
  c2_sj_y = c2_sj_a * c2_sj_b;
  c2_neb_x = c2_theta_2;
  c2_oeb_x = c2_neb_x;
  c2_oeb_x = muDoubleScalarCos(c2_oeb_x);
  c2_peb_x = c2_theta_3;
  c2_qeb_x = c2_peb_x;
  c2_qeb_x = muDoubleScalarCos(c2_qeb_x);
  c2_tj_a = c2_oeb_x;
  c2_tj_b = c2_qeb_x;
  c2_tj_y = c2_tj_a * c2_tj_b;
  c2_reb_x = c2_theta_1;
  c2_seb_x = c2_reb_x;
  c2_seb_x = muDoubleScalarSin(c2_seb_x);
  c2_uj_a = c2_tj_y;
  c2_uj_b = c2_seb_x;
  c2_uj_y = c2_uj_a * c2_uj_b;
  c2_vj_a = c2_geb_x;
  c2_vj_b = c2_sj_y - c2_uj_y;
  c2_vj_y = c2_vj_a * c2_vj_b;
  c2_wj_a = c2_pdb_x;
  c2_wj_b = c2_qj_y - c2_vj_y;
  c2_wj_y = c2_wj_a * c2_wj_b;
  c2_teb_x = c2_theta_6;
  c2_ueb_x = c2_teb_x;
  c2_ueb_x = muDoubleScalarSin(c2_ueb_x);
  c2_veb_x = c2_theta_1;
  c2_web_x = c2_veb_x;
  c2_web_x = muDoubleScalarCos(c2_web_x);
  c2_xeb_x = c2_theta_5;
  c2_yeb_x = c2_xeb_x;
  c2_yeb_x = muDoubleScalarSin(c2_yeb_x);
  c2_xj_a = c2_web_x;
  c2_xj_b = c2_yeb_x;
  c2_xj_y = c2_xj_a * c2_xj_b;
  c2_afb_x = c2_theta_5;
  c2_bfb_x = c2_afb_x;
  c2_bfb_x = muDoubleScalarCos(c2_bfb_x);
  c2_cfb_x = c2_theta_4;
  c2_dfb_x = c2_cfb_x;
  c2_dfb_x = muDoubleScalarCos(c2_dfb_x);
  c2_efb_x = c2_theta_1;
  c2_ffb_x = c2_efb_x;
  c2_ffb_x = muDoubleScalarSin(c2_ffb_x);
  c2_gfb_x = c2_theta_2;
  c2_hfb_x = c2_gfb_x;
  c2_hfb_x = muDoubleScalarSin(c2_hfb_x);
  c2_yj_a = c2_ffb_x;
  c2_yj_b = c2_hfb_x;
  c2_yj_y = c2_yj_a * c2_yj_b;
  c2_ifb_x = c2_theta_3;
  c2_jfb_x = c2_ifb_x;
  c2_jfb_x = muDoubleScalarSin(c2_jfb_x);
  c2_ak_a = c2_yj_y;
  c2_ak_b = c2_jfb_x;
  c2_ak_y = c2_ak_a * c2_ak_b;
  c2_kfb_x = c2_theta_2;
  c2_lfb_x = c2_kfb_x;
  c2_lfb_x = muDoubleScalarCos(c2_lfb_x);
  c2_mfb_x = c2_theta_3;
  c2_nfb_x = c2_mfb_x;
  c2_nfb_x = muDoubleScalarCos(c2_nfb_x);
  c2_bk_a = c2_lfb_x;
  c2_bk_b = c2_nfb_x;
  c2_bk_y = c2_bk_a * c2_bk_b;
  c2_ofb_x = c2_theta_1;
  c2_pfb_x = c2_ofb_x;
  c2_pfb_x = muDoubleScalarSin(c2_pfb_x);
  c2_ck_a = c2_bk_y;
  c2_ck_b = c2_pfb_x;
  c2_ck_y = c2_ck_a * c2_ck_b;
  c2_dk_a = c2_dfb_x;
  c2_dk_b = c2_ak_y - c2_ck_y;
  c2_dk_y = c2_dk_a * c2_dk_b;
  c2_qfb_x = c2_theta_4;
  c2_rfb_x = c2_qfb_x;
  c2_rfb_x = muDoubleScalarSin(c2_rfb_x);
  c2_sfb_x = c2_theta_2;
  c2_tfb_x = c2_sfb_x;
  c2_tfb_x = muDoubleScalarCos(c2_tfb_x);
  c2_ufb_x = c2_theta_1;
  c2_vfb_x = c2_ufb_x;
  c2_vfb_x = muDoubleScalarSin(c2_vfb_x);
  c2_ek_a = c2_tfb_x;
  c2_ek_b = c2_vfb_x;
  c2_ek_y = c2_ek_a * c2_ek_b;
  c2_wfb_x = c2_theta_3;
  c2_xfb_x = c2_wfb_x;
  c2_xfb_x = muDoubleScalarSin(c2_xfb_x);
  c2_fk_a = c2_ek_y;
  c2_fk_b = c2_xfb_x;
  c2_fk_y = c2_fk_a * c2_fk_b;
  c2_yfb_x = c2_theta_3;
  c2_agb_x = c2_yfb_x;
  c2_agb_x = muDoubleScalarCos(c2_agb_x);
  c2_bgb_x = c2_theta_1;
  c2_cgb_x = c2_bgb_x;
  c2_cgb_x = muDoubleScalarSin(c2_cgb_x);
  c2_gk_a = c2_agb_x;
  c2_gk_b = c2_cgb_x;
  c2_gk_y = c2_gk_a * c2_gk_b;
  c2_dgb_x = c2_theta_2;
  c2_egb_x = c2_dgb_x;
  c2_egb_x = muDoubleScalarSin(c2_egb_x);
  c2_hk_a = c2_gk_y;
  c2_hk_b = c2_egb_x;
  c2_hk_y = c2_hk_a * c2_hk_b;
  c2_ik_a = c2_rfb_x;
  c2_ik_b = c2_fk_y + c2_hk_y;
  c2_ik_y = c2_ik_a * c2_ik_b;
  c2_jk_a = c2_bfb_x;
  c2_jk_b = c2_dk_y + c2_ik_y;
  c2_jk_y = c2_jk_a * c2_jk_b;
  c2_kk_a = c2_ueb_x;
  c2_kk_b = c2_xj_y + c2_jk_y;
  c2_kk_y = c2_kk_a * c2_kk_b;
  c2_fgb_x = c2_theta_6;
  c2_ggb_x = c2_fgb_x;
  c2_ggb_x = muDoubleScalarCos(c2_ggb_x);
  c2_hgb_x = c2_theta_4;
  c2_igb_x = c2_hgb_x;
  c2_igb_x = muDoubleScalarCos(c2_igb_x);
  c2_jgb_x = c2_theta_2;
  c2_kgb_x = c2_jgb_x;
  c2_kgb_x = muDoubleScalarCos(c2_kgb_x);
  c2_lgb_x = c2_theta_1;
  c2_mgb_x = c2_lgb_x;
  c2_mgb_x = muDoubleScalarSin(c2_mgb_x);
  c2_lk_a = c2_kgb_x;
  c2_lk_b = c2_mgb_x;
  c2_lk_y = c2_lk_a * c2_lk_b;
  c2_ngb_x = c2_theta_3;
  c2_ogb_x = c2_ngb_x;
  c2_ogb_x = muDoubleScalarSin(c2_ogb_x);
  c2_mk_a = c2_lk_y;
  c2_mk_b = c2_ogb_x;
  c2_mk_y = c2_mk_a * c2_mk_b;
  c2_pgb_x = c2_theta_3;
  c2_qgb_x = c2_pgb_x;
  c2_qgb_x = muDoubleScalarCos(c2_qgb_x);
  c2_rgb_x = c2_theta_1;
  c2_sgb_x = c2_rgb_x;
  c2_sgb_x = muDoubleScalarSin(c2_sgb_x);
  c2_nk_a = c2_qgb_x;
  c2_nk_b = c2_sgb_x;
  c2_nk_y = c2_nk_a * c2_nk_b;
  c2_tgb_x = c2_theta_2;
  c2_ugb_x = c2_tgb_x;
  c2_ugb_x = muDoubleScalarSin(c2_ugb_x);
  c2_ok_a = c2_nk_y;
  c2_ok_b = c2_ugb_x;
  c2_ok_y = c2_ok_a * c2_ok_b;
  c2_pk_a = c2_igb_x;
  c2_pk_b = c2_mk_y + c2_ok_y;
  c2_pk_y = c2_pk_a * c2_pk_b;
  c2_vgb_x = c2_theta_4;
  c2_wgb_x = c2_vgb_x;
  c2_wgb_x = muDoubleScalarSin(c2_wgb_x);
  c2_xgb_x = c2_theta_1;
  c2_ygb_x = c2_xgb_x;
  c2_ygb_x = muDoubleScalarSin(c2_ygb_x);
  c2_ahb_x = c2_theta_2;
  c2_bhb_x = c2_ahb_x;
  c2_bhb_x = muDoubleScalarSin(c2_bhb_x);
  c2_qk_a = c2_ygb_x;
  c2_qk_b = c2_bhb_x;
  c2_qk_y = c2_qk_a * c2_qk_b;
  c2_chb_x = c2_theta_3;
  c2_dhb_x = c2_chb_x;
  c2_dhb_x = muDoubleScalarSin(c2_dhb_x);
  c2_rk_a = c2_qk_y;
  c2_rk_b = c2_dhb_x;
  c2_rk_y = c2_rk_a * c2_rk_b;
  c2_ehb_x = c2_theta_2;
  c2_fhb_x = c2_ehb_x;
  c2_fhb_x = muDoubleScalarCos(c2_fhb_x);
  c2_ghb_x = c2_theta_3;
  c2_hhb_x = c2_ghb_x;
  c2_hhb_x = muDoubleScalarCos(c2_hhb_x);
  c2_sk_a = c2_fhb_x;
  c2_sk_b = c2_hhb_x;
  c2_sk_y = c2_sk_a * c2_sk_b;
  c2_ihb_x = c2_theta_1;
  c2_jhb_x = c2_ihb_x;
  c2_jhb_x = muDoubleScalarSin(c2_jhb_x);
  c2_tk_a = c2_sk_y;
  c2_tk_b = c2_jhb_x;
  c2_tk_y = c2_tk_a * c2_tk_b;
  c2_uk_a = c2_wgb_x;
  c2_uk_b = c2_rk_y - c2_tk_y;
  c2_uk_y = c2_uk_a * c2_uk_b;
  c2_vk_a = c2_ggb_x;
  c2_vk_b = c2_pk_y - c2_uk_y;
  c2_vk_y = c2_vk_a * c2_vk_b;
  c2_khb_x = c2_theta_5;
  c2_lhb_x = c2_khb_x;
  c2_lhb_x = muDoubleScalarSin(c2_lhb_x);
  c2_mhb_x = c2_theta_4;
  c2_nhb_x = c2_mhb_x;
  c2_nhb_x = muDoubleScalarCos(c2_nhb_x);
  c2_ohb_x = c2_theta_1;
  c2_phb_x = c2_ohb_x;
  c2_phb_x = muDoubleScalarSin(c2_phb_x);
  c2_qhb_x = c2_theta_2;
  c2_rhb_x = c2_qhb_x;
  c2_rhb_x = muDoubleScalarSin(c2_rhb_x);
  c2_wk_a = c2_phb_x;
  c2_wk_b = c2_rhb_x;
  c2_wk_y = c2_wk_a * c2_wk_b;
  c2_shb_x = c2_theta_3;
  c2_thb_x = c2_shb_x;
  c2_thb_x = muDoubleScalarSin(c2_thb_x);
  c2_xk_a = c2_wk_y;
  c2_xk_b = c2_thb_x;
  c2_xk_y = c2_xk_a * c2_xk_b;
  c2_uhb_x = c2_theta_2;
  c2_vhb_x = c2_uhb_x;
  c2_vhb_x = muDoubleScalarCos(c2_vhb_x);
  c2_whb_x = c2_theta_3;
  c2_xhb_x = c2_whb_x;
  c2_xhb_x = muDoubleScalarCos(c2_xhb_x);
  c2_yk_a = c2_vhb_x;
  c2_yk_b = c2_xhb_x;
  c2_yk_y = c2_yk_a * c2_yk_b;
  c2_yhb_x = c2_theta_1;
  c2_aib_x = c2_yhb_x;
  c2_aib_x = muDoubleScalarSin(c2_aib_x);
  c2_al_a = c2_yk_y;
  c2_al_b = c2_aib_x;
  c2_al_y = c2_al_a * c2_al_b;
  c2_bl_a = c2_nhb_x;
  c2_bl_b = c2_xk_y - c2_al_y;
  c2_bl_y = c2_bl_a * c2_bl_b;
  c2_bib_x = c2_theta_4;
  c2_cib_x = c2_bib_x;
  c2_cib_x = muDoubleScalarSin(c2_cib_x);
  c2_dib_x = c2_theta_2;
  c2_eib_x = c2_dib_x;
  c2_eib_x = muDoubleScalarCos(c2_eib_x);
  c2_fib_x = c2_theta_1;
  c2_gib_x = c2_fib_x;
  c2_gib_x = muDoubleScalarSin(c2_gib_x);
  c2_cl_a = c2_eib_x;
  c2_cl_b = c2_gib_x;
  c2_cl_y = c2_cl_a * c2_cl_b;
  c2_hib_x = c2_theta_3;
  c2_iib_x = c2_hib_x;
  c2_iib_x = muDoubleScalarSin(c2_iib_x);
  c2_dl_a = c2_cl_y;
  c2_dl_b = c2_iib_x;
  c2_dl_y = c2_dl_a * c2_dl_b;
  c2_jib_x = c2_theta_3;
  c2_kib_x = c2_jib_x;
  c2_kib_x = muDoubleScalarCos(c2_kib_x);
  c2_lib_x = c2_theta_1;
  c2_mib_x = c2_lib_x;
  c2_mib_x = muDoubleScalarSin(c2_mib_x);
  c2_el_a = c2_kib_x;
  c2_el_b = c2_mib_x;
  c2_el_y = c2_el_a * c2_el_b;
  c2_nib_x = c2_theta_2;
  c2_oib_x = c2_nib_x;
  c2_oib_x = muDoubleScalarSin(c2_oib_x);
  c2_fl_a = c2_el_y;
  c2_fl_b = c2_oib_x;
  c2_fl_y = c2_fl_a * c2_fl_b;
  c2_gl_a = c2_cib_x;
  c2_gl_b = c2_dl_y + c2_fl_y;
  c2_gl_y = c2_gl_a * c2_gl_b;
  c2_hl_a = c2_lhb_x;
  c2_hl_b = c2_bl_y + c2_gl_y;
  c2_hl_y = c2_hl_a * c2_hl_b;
  c2_pib_x = c2_theta_1;
  c2_qib_x = c2_pib_x;
  c2_qib_x = muDoubleScalarCos(c2_qib_x);
  c2_rib_x = c2_theta_5;
  c2_sib_x = c2_rib_x;
  c2_sib_x = muDoubleScalarCos(c2_sib_x);
  c2_il_a = c2_qib_x;
  c2_il_b = c2_sib_x;
  c2_il_y = c2_il_a * c2_il_b;
  c2_tib_x = c2_theta_6;
  c2_uib_x = c2_tib_x;
  c2_uib_x = muDoubleScalarSin(c2_uib_x);
  c2_vib_x = c2_theta_4;
  c2_wib_x = c2_vib_x;
  c2_wib_x = muDoubleScalarCos(c2_wib_x);
  c2_xib_x = c2_theta_2;
  c2_yib_x = c2_xib_x;
  c2_yib_x = muDoubleScalarCos(c2_yib_x);
  c2_ajb_x = c2_theta_3;
  c2_bjb_x = c2_ajb_x;
  c2_bjb_x = muDoubleScalarCos(c2_bjb_x);
  c2_jl_a = c2_yib_x;
  c2_jl_b = c2_bjb_x;
  c2_jl_y = c2_jl_a * c2_jl_b;
  c2_cjb_x = c2_theta_2;
  c2_djb_x = c2_cjb_x;
  c2_djb_x = muDoubleScalarSin(c2_djb_x);
  c2_ejb_x = c2_theta_3;
  c2_fjb_x = c2_ejb_x;
  c2_fjb_x = muDoubleScalarSin(c2_fjb_x);
  c2_kl_a = c2_djb_x;
  c2_kl_b = c2_fjb_x;
  c2_kl_y = c2_kl_a * c2_kl_b;
  c2_ll_a = c2_wib_x;
  c2_ll_b = c2_jl_y - c2_kl_y;
  c2_ll_y = c2_ll_a * c2_ll_b;
  c2_gjb_x = c2_theta_4;
  c2_hjb_x = c2_gjb_x;
  c2_hjb_x = muDoubleScalarSin(c2_hjb_x);
  c2_ijb_x = c2_theta_2;
  c2_jjb_x = c2_ijb_x;
  c2_jjb_x = muDoubleScalarCos(c2_jjb_x);
  c2_kjb_x = c2_theta_3;
  c2_ljb_x = c2_kjb_x;
  c2_ljb_x = muDoubleScalarSin(c2_ljb_x);
  c2_ml_a = c2_jjb_x;
  c2_ml_b = c2_ljb_x;
  c2_ml_y = c2_ml_a * c2_ml_b;
  c2_mjb_x = c2_theta_3;
  c2_njb_x = c2_mjb_x;
  c2_njb_x = muDoubleScalarCos(c2_njb_x);
  c2_ojb_x = c2_theta_2;
  c2_pjb_x = c2_ojb_x;
  c2_pjb_x = muDoubleScalarSin(c2_pjb_x);
  c2_nl_a = c2_njb_x;
  c2_nl_b = c2_pjb_x;
  c2_nl_y = c2_nl_a * c2_nl_b;
  c2_ol_a = c2_hjb_x;
  c2_ol_b = c2_ml_y + c2_nl_y;
  c2_ol_y = c2_ol_a * c2_ol_b;
  c2_pl_a = c2_uib_x;
  c2_pl_b = c2_ll_y - c2_ol_y;
  c2_pl_y = c2_pl_a * c2_pl_b;
  c2_qjb_x = c2_theta_5;
  c2_rjb_x = c2_qjb_x;
  c2_rjb_x = muDoubleScalarCos(c2_rjb_x);
  c2_sjb_x = c2_theta_6;
  c2_tjb_x = c2_sjb_x;
  c2_tjb_x = muDoubleScalarCos(c2_tjb_x);
  c2_ql_a = c2_rjb_x;
  c2_ql_b = c2_tjb_x;
  c2_ql_y = c2_ql_a * c2_ql_b;
  c2_ujb_x = c2_theta_4;
  c2_vjb_x = c2_ujb_x;
  c2_vjb_x = muDoubleScalarCos(c2_vjb_x);
  c2_wjb_x = c2_theta_2;
  c2_xjb_x = c2_wjb_x;
  c2_xjb_x = muDoubleScalarCos(c2_xjb_x);
  c2_yjb_x = c2_theta_3;
  c2_akb_x = c2_yjb_x;
  c2_akb_x = muDoubleScalarSin(c2_akb_x);
  c2_rl_a = c2_xjb_x;
  c2_rl_b = c2_akb_x;
  c2_rl_y = c2_rl_a * c2_rl_b;
  c2_bkb_x = c2_theta_3;
  c2_ckb_x = c2_bkb_x;
  c2_ckb_x = muDoubleScalarCos(c2_ckb_x);
  c2_dkb_x = c2_theta_2;
  c2_ekb_x = c2_dkb_x;
  c2_ekb_x = muDoubleScalarSin(c2_ekb_x);
  c2_sl_a = c2_ckb_x;
  c2_sl_b = c2_ekb_x;
  c2_sl_y = c2_sl_a * c2_sl_b;
  c2_tl_a = c2_vjb_x;
  c2_tl_b = c2_rl_y + c2_sl_y;
  c2_tl_y = c2_tl_a * c2_tl_b;
  c2_fkb_x = c2_theta_4;
  c2_gkb_x = c2_fkb_x;
  c2_gkb_x = muDoubleScalarSin(c2_gkb_x);
  c2_hkb_x = c2_theta_2;
  c2_ikb_x = c2_hkb_x;
  c2_ikb_x = muDoubleScalarCos(c2_ikb_x);
  c2_jkb_x = c2_theta_3;
  c2_kkb_x = c2_jkb_x;
  c2_kkb_x = muDoubleScalarCos(c2_kkb_x);
  c2_ul_a = c2_ikb_x;
  c2_ul_b = c2_kkb_x;
  c2_ul_y = c2_ul_a * c2_ul_b;
  c2_lkb_x = c2_theta_2;
  c2_mkb_x = c2_lkb_x;
  c2_mkb_x = muDoubleScalarSin(c2_mkb_x);
  c2_nkb_x = c2_theta_3;
  c2_okb_x = c2_nkb_x;
  c2_okb_x = muDoubleScalarSin(c2_okb_x);
  c2_vl_a = c2_mkb_x;
  c2_vl_b = c2_okb_x;
  c2_vl_y = c2_vl_a * c2_vl_b;
  c2_wl_a = c2_gkb_x;
  c2_wl_b = c2_ul_y - c2_vl_y;
  c2_wl_y = c2_wl_a * c2_wl_b;
  c2_xl_a = c2_ql_y;
  c2_xl_b = c2_tl_y + c2_wl_y;
  c2_xl_y = c2_xl_a * c2_xl_b;
  c2_pkb_x = c2_theta_6;
  c2_qkb_x = c2_pkb_x;
  c2_qkb_x = muDoubleScalarCos(c2_qkb_x);
  c2_rkb_x = c2_theta_4;
  c2_skb_x = c2_rkb_x;
  c2_skb_x = muDoubleScalarCos(c2_skb_x);
  c2_tkb_x = c2_theta_2;
  c2_ukb_x = c2_tkb_x;
  c2_ukb_x = muDoubleScalarCos(c2_ukb_x);
  c2_vkb_x = c2_theta_3;
  c2_wkb_x = c2_vkb_x;
  c2_wkb_x = muDoubleScalarCos(c2_wkb_x);
  c2_yl_a = c2_ukb_x;
  c2_yl_b = c2_wkb_x;
  c2_yl_y = c2_yl_a * c2_yl_b;
  c2_xkb_x = c2_theta_2;
  c2_ykb_x = c2_xkb_x;
  c2_ykb_x = muDoubleScalarSin(c2_ykb_x);
  c2_alb_x = c2_theta_3;
  c2_blb_x = c2_alb_x;
  c2_blb_x = muDoubleScalarSin(c2_blb_x);
  c2_am_a = c2_ykb_x;
  c2_am_b = c2_blb_x;
  c2_am_y = c2_am_a * c2_am_b;
  c2_bm_a = c2_skb_x;
  c2_bm_b = c2_yl_y - c2_am_y;
  c2_bm_y = c2_bm_a * c2_bm_b;
  c2_clb_x = c2_theta_4;
  c2_dlb_x = c2_clb_x;
  c2_dlb_x = muDoubleScalarSin(c2_dlb_x);
  c2_elb_x = c2_theta_2;
  c2_flb_x = c2_elb_x;
  c2_flb_x = muDoubleScalarCos(c2_flb_x);
  c2_glb_x = c2_theta_3;
  c2_hlb_x = c2_glb_x;
  c2_hlb_x = muDoubleScalarSin(c2_hlb_x);
  c2_cm_a = c2_flb_x;
  c2_cm_b = c2_hlb_x;
  c2_cm_y = c2_cm_a * c2_cm_b;
  c2_ilb_x = c2_theta_3;
  c2_jlb_x = c2_ilb_x;
  c2_jlb_x = muDoubleScalarCos(c2_jlb_x);
  c2_klb_x = c2_theta_2;
  c2_llb_x = c2_klb_x;
  c2_llb_x = muDoubleScalarSin(c2_llb_x);
  c2_dm_a = c2_jlb_x;
  c2_dm_b = c2_llb_x;
  c2_dm_y = c2_dm_a * c2_dm_b;
  c2_em_a = c2_dlb_x;
  c2_em_b = c2_cm_y + c2_dm_y;
  c2_em_y = c2_em_a * c2_em_b;
  c2_fm_a = c2_qkb_x;
  c2_fm_b = c2_bm_y - c2_em_y;
  c2_fm_y = c2_fm_a * c2_fm_b;
  c2_mlb_x = c2_theta_5;
  c2_nlb_x = c2_mlb_x;
  c2_nlb_x = muDoubleScalarCos(c2_nlb_x);
  c2_olb_x = c2_theta_6;
  c2_plb_x = c2_olb_x;
  c2_plb_x = muDoubleScalarSin(c2_plb_x);
  c2_gm_a = c2_nlb_x;
  c2_gm_b = c2_plb_x;
  c2_gm_y = c2_gm_a * c2_gm_b;
  c2_qlb_x = c2_theta_4;
  c2_rlb_x = c2_qlb_x;
  c2_rlb_x = muDoubleScalarCos(c2_rlb_x);
  c2_slb_x = c2_theta_2;
  c2_tlb_x = c2_slb_x;
  c2_tlb_x = muDoubleScalarCos(c2_tlb_x);
  c2_ulb_x = c2_theta_3;
  c2_vlb_x = c2_ulb_x;
  c2_vlb_x = muDoubleScalarSin(c2_vlb_x);
  c2_hm_a = c2_tlb_x;
  c2_hm_b = c2_vlb_x;
  c2_hm_y = c2_hm_a * c2_hm_b;
  c2_wlb_x = c2_theta_3;
  c2_xlb_x = c2_wlb_x;
  c2_xlb_x = muDoubleScalarCos(c2_xlb_x);
  c2_ylb_x = c2_theta_2;
  c2_amb_x = c2_ylb_x;
  c2_amb_x = muDoubleScalarSin(c2_amb_x);
  c2_im_a = c2_xlb_x;
  c2_im_b = c2_amb_x;
  c2_im_y = c2_im_a * c2_im_b;
  c2_jm_a = c2_rlb_x;
  c2_jm_b = c2_hm_y + c2_im_y;
  c2_jm_y = c2_jm_a * c2_jm_b;
  c2_bmb_x = c2_theta_4;
  c2_cmb_x = c2_bmb_x;
  c2_cmb_x = muDoubleScalarSin(c2_cmb_x);
  c2_dmb_x = c2_theta_2;
  c2_emb_x = c2_dmb_x;
  c2_emb_x = muDoubleScalarCos(c2_emb_x);
  c2_fmb_x = c2_theta_3;
  c2_gmb_x = c2_fmb_x;
  c2_gmb_x = muDoubleScalarCos(c2_gmb_x);
  c2_km_a = c2_emb_x;
  c2_km_b = c2_gmb_x;
  c2_km_y = c2_km_a * c2_km_b;
  c2_hmb_x = c2_theta_2;
  c2_imb_x = c2_hmb_x;
  c2_imb_x = muDoubleScalarSin(c2_imb_x);
  c2_jmb_x = c2_theta_3;
  c2_kmb_x = c2_jmb_x;
  c2_kmb_x = muDoubleScalarSin(c2_kmb_x);
  c2_lm_a = c2_imb_x;
  c2_lm_b = c2_kmb_x;
  c2_lm_y = c2_lm_a * c2_lm_b;
  c2_mm_a = c2_cmb_x;
  c2_mm_b = c2_km_y - c2_lm_y;
  c2_mm_y = c2_mm_a * c2_mm_b;
  c2_nm_a = c2_gm_y;
  c2_nm_b = c2_jm_y + c2_mm_y;
  c2_nm_y = c2_nm_a * c2_nm_b;
  c2_lmb_x = c2_theta_5;
  c2_mmb_x = c2_lmb_x;
  c2_mmb_x = muDoubleScalarSin(c2_mmb_x);
  c2_nmb_x = c2_theta_4;
  c2_omb_x = c2_nmb_x;
  c2_omb_x = muDoubleScalarCos(c2_omb_x);
  c2_pmb_x = c2_theta_2;
  c2_qmb_x = c2_pmb_x;
  c2_qmb_x = muDoubleScalarCos(c2_qmb_x);
  c2_rmb_x = c2_theta_3;
  c2_smb_x = c2_rmb_x;
  c2_smb_x = muDoubleScalarSin(c2_smb_x);
  c2_om_a = c2_qmb_x;
  c2_om_b = c2_smb_x;
  c2_om_y = c2_om_a * c2_om_b;
  c2_tmb_x = c2_theta_3;
  c2_umb_x = c2_tmb_x;
  c2_umb_x = muDoubleScalarCos(c2_umb_x);
  c2_vmb_x = c2_theta_2;
  c2_wmb_x = c2_vmb_x;
  c2_wmb_x = muDoubleScalarSin(c2_wmb_x);
  c2_pm_a = c2_umb_x;
  c2_pm_b = c2_wmb_x;
  c2_pm_y = c2_pm_a * c2_pm_b;
  c2_qm_a = c2_omb_x;
  c2_qm_b = c2_om_y + c2_pm_y;
  c2_qm_y = c2_qm_a * c2_qm_b;
  c2_xmb_x = c2_theta_4;
  c2_ymb_x = c2_xmb_x;
  c2_ymb_x = muDoubleScalarSin(c2_ymb_x);
  c2_anb_x = c2_theta_2;
  c2_bnb_x = c2_anb_x;
  c2_bnb_x = muDoubleScalarCos(c2_bnb_x);
  c2_cnb_x = c2_theta_3;
  c2_dnb_x = c2_cnb_x;
  c2_dnb_x = muDoubleScalarCos(c2_dnb_x);
  c2_rm_a = c2_bnb_x;
  c2_rm_b = c2_dnb_x;
  c2_rm_y = c2_rm_a * c2_rm_b;
  c2_enb_x = c2_theta_2;
  c2_fnb_x = c2_enb_x;
  c2_fnb_x = muDoubleScalarSin(c2_fnb_x);
  c2_gnb_x = c2_theta_3;
  c2_hnb_x = c2_gnb_x;
  c2_hnb_x = muDoubleScalarSin(c2_hnb_x);
  c2_sm_a = c2_fnb_x;
  c2_sm_b = c2_hnb_x;
  c2_sm_y = c2_sm_a * c2_sm_b;
  c2_tm_a = c2_ymb_x;
  c2_tm_b = c2_rm_y - c2_sm_y;
  c2_tm_y = c2_tm_a * c2_tm_b;
  c2_um_a = -c2_mmb_x;
  c2_um_b = c2_qm_y + c2_tm_y;
  c2_um_y = c2_um_a * c2_um_b;
  c2_R6[0] = c2_bh_y - c2_mh_y;
  c2_R6[3] = c2_ai_y - c2_li_y;
  c2_R6[6] = c2_mi_y + c2_xi_y;
  c2_R6[1] = c2_lj_y - c2_wj_y;
  c2_R6[4] = c2_kk_y - c2_vk_y;
  c2_R6[7] = c2_hl_y - c2_il_y;
  c2_R6[2] = c2_pl_y + c2_xl_y;
  c2_R6[5] = c2_fm_y - c2_nm_y;
  c2_R6[8] = c2_um_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  for (c2_i28 = 0; c2_i28 < 3; c2_i28++) {
    c2_d1[c2_i28] = c2_dv13[c2_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_inb_x = c2_theta_1;
  c2_jnb_x = c2_inb_x;
  c2_jnb_x = muDoubleScalarCos(c2_jnb_x);
  c2_vm_b = c2_jnb_x;
  c2_vm_y = 17.0 * c2_vm_b;
  c2_knb_x = c2_theta_2;
  c2_lnb_x = c2_knb_x;
  c2_lnb_x = muDoubleScalarCos(c2_lnb_x);
  c2_vm_a = c2_vm_y;
  c2_wm_b = c2_lnb_x;
  c2_wm_y = c2_vm_a * c2_wm_b;
  c2_A = -c2_wm_y;
  c2_mnb_x = c2_A;
  c2_nnb_x = c2_mnb_x;
  c2_xm_y = c2_nnb_x / 40.0;
  c2_onb_x = c2_theta_2;
  c2_pnb_x = c2_onb_x;
  c2_pnb_x = muDoubleScalarCos(c2_pnb_x);
  c2_xm_b = c2_pnb_x;
  c2_ym_y = 17.0 * c2_xm_b;
  c2_qnb_x = c2_theta_1;
  c2_rnb_x = c2_qnb_x;
  c2_rnb_x = muDoubleScalarSin(c2_rnb_x);
  c2_wm_a = c2_ym_y;
  c2_ym_b = c2_rnb_x;
  c2_an_y = c2_wm_a * c2_ym_b;
  c2_b_A = -c2_an_y;
  c2_snb_x = c2_b_A;
  c2_tnb_x = c2_snb_x;
  c2_bn_y = c2_tnb_x / 40.0;
  c2_unb_x = c2_theta_2;
  c2_vnb_x = c2_unb_x;
  c2_vnb_x = muDoubleScalarSin(c2_vnb_x);
  c2_an_b = c2_vnb_x;
  c2_cn_y = 17.0 * c2_an_b;
  c2_c_A = c2_cn_y;
  c2_wnb_x = c2_c_A;
  c2_xnb_x = c2_wnb_x;
  c2_dn_y = c2_xnb_x / 40.0;
  c2_d2[0] = c2_xm_y;
  c2_d2[1] = c2_bn_y;
  c2_d2[2] = 0.0892 - c2_dn_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_ynb_x = c2_theta_1;
  c2_aob_x = c2_ynb_x;
  c2_aob_x = muDoubleScalarCos(c2_aob_x);
  c2_bn_b = c2_aob_x;
  c2_en_y = 39243.0 * c2_bn_b;
  c2_bob_x = c2_theta_2;
  c2_cob_x = c2_bob_x;
  c2_cob_x = muDoubleScalarSin(c2_cob_x);
  c2_xm_a = c2_en_y;
  c2_cn_b = c2_cob_x;
  c2_fn_y = c2_xm_a * c2_cn_b;
  c2_dob_x = c2_theta_3;
  c2_eob_x = c2_dob_x;
  c2_eob_x = muDoubleScalarSin(c2_eob_x);
  c2_ym_a = c2_fn_y;
  c2_dn_b = c2_eob_x;
  c2_gn_y = c2_ym_a * c2_dn_b;
  c2_d_A = c2_gn_y;
  c2_fob_x = c2_d_A;
  c2_gob_x = c2_fob_x;
  c2_hn_y = c2_gob_x / 100000.0;
  c2_hob_x = c2_theta_1;
  c2_iob_x = c2_hob_x;
  c2_iob_x = muDoubleScalarCos(c2_iob_x);
  c2_en_b = c2_iob_x;
  c2_in_y = 17.0 * c2_en_b;
  c2_job_x = c2_theta_2;
  c2_kob_x = c2_job_x;
  c2_kob_x = muDoubleScalarCos(c2_kob_x);
  c2_an_a = c2_in_y;
  c2_fn_b = c2_kob_x;
  c2_jn_y = c2_an_a * c2_fn_b;
  c2_e_A = c2_jn_y;
  c2_lob_x = c2_e_A;
  c2_mob_x = c2_lob_x;
  c2_kn_y = c2_mob_x / 40.0;
  c2_nob_x = c2_theta_1;
  c2_oob_x = c2_nob_x;
  c2_oob_x = muDoubleScalarCos(c2_oob_x);
  c2_gn_b = c2_oob_x;
  c2_ln_y = 39243.0 * c2_gn_b;
  c2_pob_x = c2_theta_2;
  c2_qob_x = c2_pob_x;
  c2_qob_x = muDoubleScalarCos(c2_qob_x);
  c2_bn_a = c2_ln_y;
  c2_hn_b = c2_qob_x;
  c2_mn_y = c2_bn_a * c2_hn_b;
  c2_rob_x = c2_theta_3;
  c2_sob_x = c2_rob_x;
  c2_sob_x = muDoubleScalarCos(c2_sob_x);
  c2_cn_a = c2_mn_y;
  c2_in_b = c2_sob_x;
  c2_nn_y = c2_cn_a * c2_in_b;
  c2_f_A = c2_nn_y;
  c2_tob_x = c2_f_A;
  c2_uob_x = c2_tob_x;
  c2_on_y = c2_uob_x / 100000.0;
  c2_vob_x = c2_theta_1;
  c2_wob_x = c2_vob_x;
  c2_wob_x = muDoubleScalarSin(c2_wob_x);
  c2_jn_b = c2_wob_x;
  c2_pn_y = 39243.0 * c2_jn_b;
  c2_xob_x = c2_theta_2;
  c2_yob_x = c2_xob_x;
  c2_yob_x = muDoubleScalarSin(c2_yob_x);
  c2_dn_a = c2_pn_y;
  c2_kn_b = c2_yob_x;
  c2_qn_y = c2_dn_a * c2_kn_b;
  c2_apb_x = c2_theta_3;
  c2_bpb_x = c2_apb_x;
  c2_bpb_x = muDoubleScalarSin(c2_bpb_x);
  c2_en_a = c2_qn_y;
  c2_ln_b = c2_bpb_x;
  c2_rn_y = c2_en_a * c2_ln_b;
  c2_g_A = c2_rn_y;
  c2_cpb_x = c2_g_A;
  c2_dpb_x = c2_cpb_x;
  c2_sn_y = c2_dpb_x / 100000.0;
  c2_epb_x = c2_theta_2;
  c2_fpb_x = c2_epb_x;
  c2_fpb_x = muDoubleScalarCos(c2_fpb_x);
  c2_mn_b = c2_fpb_x;
  c2_tn_y = 17.0 * c2_mn_b;
  c2_gpb_x = c2_theta_1;
  c2_hpb_x = c2_gpb_x;
  c2_hpb_x = muDoubleScalarSin(c2_hpb_x);
  c2_fn_a = c2_tn_y;
  c2_nn_b = c2_hpb_x;
  c2_un_y = c2_fn_a * c2_nn_b;
  c2_h_A = c2_un_y;
  c2_ipb_x = c2_h_A;
  c2_jpb_x = c2_ipb_x;
  c2_vn_y = c2_jpb_x / 40.0;
  c2_kpb_x = c2_theta_2;
  c2_lpb_x = c2_kpb_x;
  c2_lpb_x = muDoubleScalarCos(c2_lpb_x);
  c2_on_b = c2_lpb_x;
  c2_wn_y = 39243.0 * c2_on_b;
  c2_mpb_x = c2_theta_3;
  c2_npb_x = c2_mpb_x;
  c2_npb_x = muDoubleScalarCos(c2_npb_x);
  c2_gn_a = c2_wn_y;
  c2_pn_b = c2_npb_x;
  c2_xn_y = c2_gn_a * c2_pn_b;
  c2_opb_x = c2_theta_1;
  c2_ppb_x = c2_opb_x;
  c2_ppb_x = muDoubleScalarSin(c2_ppb_x);
  c2_hn_a = c2_xn_y;
  c2_qn_b = c2_ppb_x;
  c2_yn_y = c2_hn_a * c2_qn_b;
  c2_i_A = c2_yn_y;
  c2_qpb_x = c2_i_A;
  c2_rpb_x = c2_qpb_x;
  c2_ao_y = c2_rpb_x / 100000.0;
  c2_spb_x = c2_theta_2;
  c2_tpb_x = c2_spb_x;
  c2_tpb_x = muDoubleScalarCos(c2_tpb_x);
  c2_rn_b = c2_tpb_x;
  c2_bo_y = 39243.0 * c2_rn_b;
  c2_upb_x = c2_theta_3;
  c2_vpb_x = c2_upb_x;
  c2_vpb_x = muDoubleScalarSin(c2_vpb_x);
  c2_in_a = c2_bo_y;
  c2_sn_b = c2_vpb_x;
  c2_co_y = c2_in_a * c2_sn_b;
  c2_j_A = c2_co_y;
  c2_wpb_x = c2_j_A;
  c2_xpb_x = c2_wpb_x;
  c2_do_y = c2_xpb_x / 100000.0;
  c2_ypb_x = c2_theta_3;
  c2_aqb_x = c2_ypb_x;
  c2_aqb_x = muDoubleScalarCos(c2_aqb_x);
  c2_tn_b = c2_aqb_x;
  c2_eo_y = 39243.0 * c2_tn_b;
  c2_bqb_x = c2_theta_2;
  c2_cqb_x = c2_bqb_x;
  c2_cqb_x = muDoubleScalarSin(c2_cqb_x);
  c2_jn_a = c2_eo_y;
  c2_un_b = c2_cqb_x;
  c2_fo_y = c2_jn_a * c2_un_b;
  c2_k_A = c2_fo_y;
  c2_dqb_x = c2_k_A;
  c2_eqb_x = c2_dqb_x;
  c2_go_y = c2_eqb_x / 100000.0;
  c2_fqb_x = c2_theta_2;
  c2_gqb_x = c2_fqb_x;
  c2_gqb_x = muDoubleScalarSin(c2_gqb_x);
  c2_vn_b = c2_gqb_x;
  c2_ho_y = 17.0 * c2_vn_b;
  c2_l_A = c2_ho_y;
  c2_hqb_x = c2_l_A;
  c2_iqb_x = c2_hqb_x;
  c2_io_y = c2_iqb_x / 40.0;
  c2_d3[0] = (c2_hn_y - c2_kn_y) - c2_on_y;
  c2_d3[1] = (c2_sn_y - c2_vn_y) - c2_ao_y;
  c2_d3[2] = ((0.0892 - c2_do_y) - c2_go_y) - c2_io_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_jqb_x = c2_theta_1;
  c2_kqb_x = c2_jqb_x;
  c2_kqb_x = muDoubleScalarSin(c2_kqb_x);
  c2_wn_b = c2_kqb_x;
  c2_jo_y = 109.0 * c2_wn_b;
  c2_m_A = c2_jo_y;
  c2_lqb_x = c2_m_A;
  c2_mqb_x = c2_lqb_x;
  c2_ko_y = c2_mqb_x / 1000.0;
  c2_nqb_x = c2_theta_1;
  c2_oqb_x = c2_nqb_x;
  c2_oqb_x = muDoubleScalarCos(c2_oqb_x);
  c2_xn_b = c2_oqb_x;
  c2_lo_y = 17.0 * c2_xn_b;
  c2_pqb_x = c2_theta_2;
  c2_qqb_x = c2_pqb_x;
  c2_qqb_x = muDoubleScalarCos(c2_qqb_x);
  c2_kn_a = c2_lo_y;
  c2_yn_b = c2_qqb_x;
  c2_mo_y = c2_kn_a * c2_yn_b;
  c2_n_A = c2_mo_y;
  c2_rqb_x = c2_n_A;
  c2_sqb_x = c2_rqb_x;
  c2_no_y = c2_sqb_x / 40.0;
  c2_tqb_x = c2_theta_1;
  c2_uqb_x = c2_tqb_x;
  c2_uqb_x = muDoubleScalarCos(c2_uqb_x);
  c2_ao_b = c2_uqb_x;
  c2_oo_y = 39243.0 * c2_ao_b;
  c2_vqb_x = c2_theta_2;
  c2_wqb_x = c2_vqb_x;
  c2_wqb_x = muDoubleScalarSin(c2_wqb_x);
  c2_ln_a = c2_oo_y;
  c2_bo_b = c2_wqb_x;
  c2_po_y = c2_ln_a * c2_bo_b;
  c2_xqb_x = c2_theta_3;
  c2_yqb_x = c2_xqb_x;
  c2_yqb_x = muDoubleScalarSin(c2_yqb_x);
  c2_mn_a = c2_po_y;
  c2_co_b = c2_yqb_x;
  c2_qo_y = c2_mn_a * c2_co_b;
  c2_o_A = c2_qo_y;
  c2_arb_x = c2_o_A;
  c2_brb_x = c2_arb_x;
  c2_ro_y = c2_brb_x / 100000.0;
  c2_crb_x = c2_theta_1;
  c2_drb_x = c2_crb_x;
  c2_drb_x = muDoubleScalarCos(c2_drb_x);
  c2_do_b = c2_drb_x;
  c2_so_y = 39243.0 * c2_do_b;
  c2_erb_x = c2_theta_2;
  c2_frb_x = c2_erb_x;
  c2_frb_x = muDoubleScalarCos(c2_frb_x);
  c2_nn_a = c2_so_y;
  c2_eo_b = c2_frb_x;
  c2_to_y = c2_nn_a * c2_eo_b;
  c2_grb_x = c2_theta_3;
  c2_hrb_x = c2_grb_x;
  c2_hrb_x = muDoubleScalarCos(c2_hrb_x);
  c2_on_a = c2_to_y;
  c2_fo_b = c2_hrb_x;
  c2_uo_y = c2_on_a * c2_fo_b;
  c2_p_A = c2_uo_y;
  c2_irb_x = c2_p_A;
  c2_jrb_x = c2_irb_x;
  c2_vo_y = c2_jrb_x / 100000.0;
  c2_krb_x = c2_theta_1;
  c2_lrb_x = c2_krb_x;
  c2_lrb_x = muDoubleScalarSin(c2_lrb_x);
  c2_go_b = c2_lrb_x;
  c2_wo_y = 39243.0 * c2_go_b;
  c2_mrb_x = c2_theta_2;
  c2_nrb_x = c2_mrb_x;
  c2_nrb_x = muDoubleScalarSin(c2_nrb_x);
  c2_pn_a = c2_wo_y;
  c2_ho_b = c2_nrb_x;
  c2_xo_y = c2_pn_a * c2_ho_b;
  c2_orb_x = c2_theta_3;
  c2_prb_x = c2_orb_x;
  c2_prb_x = muDoubleScalarSin(c2_prb_x);
  c2_qn_a = c2_xo_y;
  c2_io_b = c2_prb_x;
  c2_yo_y = c2_qn_a * c2_io_b;
  c2_q_A = c2_yo_y;
  c2_qrb_x = c2_q_A;
  c2_rrb_x = c2_qrb_x;
  c2_ap_y = c2_rrb_x / 100000.0;
  c2_srb_x = c2_theta_2;
  c2_trb_x = c2_srb_x;
  c2_trb_x = muDoubleScalarCos(c2_trb_x);
  c2_jo_b = c2_trb_x;
  c2_bp_y = 17.0 * c2_jo_b;
  c2_urb_x = c2_theta_1;
  c2_vrb_x = c2_urb_x;
  c2_vrb_x = muDoubleScalarSin(c2_vrb_x);
  c2_rn_a = c2_bp_y;
  c2_ko_b = c2_vrb_x;
  c2_cp_y = c2_rn_a * c2_ko_b;
  c2_r_A = c2_cp_y;
  c2_wrb_x = c2_r_A;
  c2_xrb_x = c2_wrb_x;
  c2_dp_y = c2_xrb_x / 40.0;
  c2_yrb_x = c2_theta_1;
  c2_asb_x = c2_yrb_x;
  c2_asb_x = muDoubleScalarCos(c2_asb_x);
  c2_lo_b = c2_asb_x;
  c2_ep_y = 109.0 * c2_lo_b;
  c2_s_A = c2_ep_y;
  c2_bsb_x = c2_s_A;
  c2_csb_x = c2_bsb_x;
  c2_fp_y = c2_csb_x / 1000.0;
  c2_dsb_x = c2_theta_2;
  c2_esb_x = c2_dsb_x;
  c2_esb_x = muDoubleScalarCos(c2_esb_x);
  c2_mo_b = c2_esb_x;
  c2_gp_y = 39243.0 * c2_mo_b;
  c2_fsb_x = c2_theta_3;
  c2_gsb_x = c2_fsb_x;
  c2_gsb_x = muDoubleScalarCos(c2_gsb_x);
  c2_sn_a = c2_gp_y;
  c2_no_b = c2_gsb_x;
  c2_hp_y = c2_sn_a * c2_no_b;
  c2_hsb_x = c2_theta_1;
  c2_isb_x = c2_hsb_x;
  c2_isb_x = muDoubleScalarSin(c2_isb_x);
  c2_tn_a = c2_hp_y;
  c2_oo_b = c2_isb_x;
  c2_ip_y = c2_tn_a * c2_oo_b;
  c2_t_A = c2_ip_y;
  c2_jsb_x = c2_t_A;
  c2_ksb_x = c2_jsb_x;
  c2_jp_y = c2_ksb_x / 100000.0;
  c2_lsb_x = c2_theta_2;
  c2_msb_x = c2_lsb_x;
  c2_msb_x = muDoubleScalarCos(c2_msb_x);
  c2_po_b = c2_msb_x;
  c2_kp_y = 39243.0 * c2_po_b;
  c2_nsb_x = c2_theta_3;
  c2_osb_x = c2_nsb_x;
  c2_osb_x = muDoubleScalarSin(c2_osb_x);
  c2_un_a = c2_kp_y;
  c2_qo_b = c2_osb_x;
  c2_lp_y = c2_un_a * c2_qo_b;
  c2_u_A = c2_lp_y;
  c2_psb_x = c2_u_A;
  c2_qsb_x = c2_psb_x;
  c2_mp_y = c2_qsb_x / 100000.0;
  c2_rsb_x = c2_theta_3;
  c2_ssb_x = c2_rsb_x;
  c2_ssb_x = muDoubleScalarCos(c2_ssb_x);
  c2_ro_b = c2_ssb_x;
  c2_np_y = 39243.0 * c2_ro_b;
  c2_tsb_x = c2_theta_2;
  c2_usb_x = c2_tsb_x;
  c2_usb_x = muDoubleScalarSin(c2_usb_x);
  c2_vn_a = c2_np_y;
  c2_so_b = c2_usb_x;
  c2_op_y = c2_vn_a * c2_so_b;
  c2_v_A = c2_op_y;
  c2_vsb_x = c2_v_A;
  c2_wsb_x = c2_vsb_x;
  c2_pp_y = c2_wsb_x / 100000.0;
  c2_xsb_x = c2_theta_2;
  c2_ysb_x = c2_xsb_x;
  c2_ysb_x = muDoubleScalarSin(c2_ysb_x);
  c2_to_b = c2_ysb_x;
  c2_qp_y = 17.0 * c2_to_b;
  c2_w_A = c2_qp_y;
  c2_atb_x = c2_w_A;
  c2_btb_x = c2_atb_x;
  c2_rp_y = c2_btb_x / 40.0;
  c2_d4[0] = ((c2_ko_y - c2_no_y) + c2_ro_y) - c2_vo_y;
  c2_d4[1] = ((c2_ap_y - c2_dp_y) - c2_fp_y) - c2_jp_y;
  c2_d4[2] = ((0.0892 - c2_mp_y) - c2_pp_y) - c2_rp_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
  c2_ctb_x = c2_theta_1;
  c2_dtb_x = c2_ctb_x;
  c2_dtb_x = muDoubleScalarSin(c2_dtb_x);
  c2_uo_b = c2_dtb_x;
  c2_sp_y = 109.0 * c2_uo_b;
  c2_x_A = c2_sp_y;
  c2_etb_x = c2_x_A;
  c2_ftb_x = c2_etb_x;
  c2_tp_y = c2_ftb_x / 1000.0;
  c2_gtb_x = c2_theta_1;
  c2_htb_x = c2_gtb_x;
  c2_htb_x = muDoubleScalarCos(c2_htb_x);
  c2_vo_b = c2_htb_x;
  c2_up_y = 17.0 * c2_vo_b;
  c2_itb_x = c2_theta_2;
  c2_jtb_x = c2_itb_x;
  c2_jtb_x = muDoubleScalarCos(c2_jtb_x);
  c2_wn_a = c2_up_y;
  c2_wo_b = c2_jtb_x;
  c2_vp_y = c2_wn_a * c2_wo_b;
  c2_y_A = c2_vp_y;
  c2_ktb_x = c2_y_A;
  c2_ltb_x = c2_ktb_x;
  c2_wp_y = c2_ltb_x / 40.0;
  c2_mtb_x = c2_theta_4;
  c2_ntb_x = c2_mtb_x;
  c2_ntb_x = muDoubleScalarCos(c2_ntb_x);
  c2_xo_b = c2_ntb_x;
  c2_xp_y = 93.0 * c2_xo_b;
  c2_otb_x = c2_theta_1;
  c2_ptb_x = c2_otb_x;
  c2_ptb_x = muDoubleScalarCos(c2_ptb_x);
  c2_qtb_x = c2_theta_2;
  c2_rtb_x = c2_qtb_x;
  c2_rtb_x = muDoubleScalarCos(c2_rtb_x);
  c2_xn_a = c2_ptb_x;
  c2_yo_b = c2_rtb_x;
  c2_yp_y = c2_xn_a * c2_yo_b;
  c2_stb_x = c2_theta_3;
  c2_ttb_x = c2_stb_x;
  c2_ttb_x = muDoubleScalarSin(c2_ttb_x);
  c2_yn_a = c2_yp_y;
  c2_ap_b = c2_ttb_x;
  c2_aq_y = c2_yn_a * c2_ap_b;
  c2_utb_x = c2_theta_1;
  c2_vtb_x = c2_utb_x;
  c2_vtb_x = muDoubleScalarCos(c2_vtb_x);
  c2_wtb_x = c2_theta_3;
  c2_xtb_x = c2_wtb_x;
  c2_xtb_x = muDoubleScalarCos(c2_xtb_x);
  c2_ao_a = c2_vtb_x;
  c2_bp_b = c2_xtb_x;
  c2_bq_y = c2_ao_a * c2_bp_b;
  c2_ytb_x = c2_theta_2;
  c2_aub_x = c2_ytb_x;
  c2_aub_x = muDoubleScalarSin(c2_aub_x);
  c2_bo_a = c2_bq_y;
  c2_cp_b = c2_aub_x;
  c2_cq_y = c2_bo_a * c2_cp_b;
  c2_co_a = c2_xp_y;
  c2_dp_b = c2_aq_y + c2_cq_y;
  c2_dq_y = c2_co_a * c2_dp_b;
  c2_ab_A = c2_dq_y;
  c2_bub_x = c2_ab_A;
  c2_cub_x = c2_bub_x;
  c2_eq_y = c2_cub_x / 1000.0;
  c2_dub_x = c2_theta_4;
  c2_eub_x = c2_dub_x;
  c2_eub_x = muDoubleScalarSin(c2_eub_x);
  c2_ep_b = c2_eub_x;
  c2_fq_y = 93.0 * c2_ep_b;
  c2_fub_x = c2_theta_1;
  c2_gub_x = c2_fub_x;
  c2_gub_x = muDoubleScalarCos(c2_gub_x);
  c2_hub_x = c2_theta_2;
  c2_iub_x = c2_hub_x;
  c2_iub_x = muDoubleScalarSin(c2_iub_x);
  c2_do_a = c2_gub_x;
  c2_fp_b = c2_iub_x;
  c2_gq_y = c2_do_a * c2_fp_b;
  c2_jub_x = c2_theta_3;
  c2_kub_x = c2_jub_x;
  c2_kub_x = muDoubleScalarSin(c2_kub_x);
  c2_eo_a = c2_gq_y;
  c2_gp_b = c2_kub_x;
  c2_hq_y = c2_eo_a * c2_gp_b;
  c2_lub_x = c2_theta_1;
  c2_mub_x = c2_lub_x;
  c2_mub_x = muDoubleScalarCos(c2_mub_x);
  c2_nub_x = c2_theta_2;
  c2_oub_x = c2_nub_x;
  c2_oub_x = muDoubleScalarCos(c2_oub_x);
  c2_fo_a = c2_mub_x;
  c2_hp_b = c2_oub_x;
  c2_iq_y = c2_fo_a * c2_hp_b;
  c2_pub_x = c2_theta_3;
  c2_qub_x = c2_pub_x;
  c2_qub_x = muDoubleScalarCos(c2_qub_x);
  c2_go_a = c2_iq_y;
  c2_ip_b = c2_qub_x;
  c2_jq_y = c2_go_a * c2_ip_b;
  c2_ho_a = c2_fq_y;
  c2_jp_b = c2_hq_y - c2_jq_y;
  c2_kq_y = c2_ho_a * c2_jp_b;
  c2_bb_A = c2_kq_y;
  c2_rub_x = c2_bb_A;
  c2_sub_x = c2_rub_x;
  c2_lq_y = c2_sub_x / 1000.0;
  c2_tub_x = c2_theta_1;
  c2_uub_x = c2_tub_x;
  c2_uub_x = muDoubleScalarCos(c2_uub_x);
  c2_kp_b = c2_uub_x;
  c2_mq_y = 39243.0 * c2_kp_b;
  c2_vub_x = c2_theta_2;
  c2_wub_x = c2_vub_x;
  c2_wub_x = muDoubleScalarSin(c2_wub_x);
  c2_io_a = c2_mq_y;
  c2_lp_b = c2_wub_x;
  c2_nq_y = c2_io_a * c2_lp_b;
  c2_xub_x = c2_theta_3;
  c2_yub_x = c2_xub_x;
  c2_yub_x = muDoubleScalarSin(c2_yub_x);
  c2_jo_a = c2_nq_y;
  c2_mp_b = c2_yub_x;
  c2_oq_y = c2_jo_a * c2_mp_b;
  c2_cb_A = c2_oq_y;
  c2_avb_x = c2_cb_A;
  c2_bvb_x = c2_avb_x;
  c2_pq_y = c2_bvb_x / 100000.0;
  c2_cvb_x = c2_theta_1;
  c2_dvb_x = c2_cvb_x;
  c2_dvb_x = muDoubleScalarCos(c2_dvb_x);
  c2_np_b = c2_dvb_x;
  c2_qq_y = 39243.0 * c2_np_b;
  c2_evb_x = c2_theta_2;
  c2_fvb_x = c2_evb_x;
  c2_fvb_x = muDoubleScalarCos(c2_fvb_x);
  c2_ko_a = c2_qq_y;
  c2_op_b = c2_fvb_x;
  c2_rq_y = c2_ko_a * c2_op_b;
  c2_gvb_x = c2_theta_3;
  c2_hvb_x = c2_gvb_x;
  c2_hvb_x = muDoubleScalarCos(c2_hvb_x);
  c2_lo_a = c2_rq_y;
  c2_pp_b = c2_hvb_x;
  c2_sq_y = c2_lo_a * c2_pp_b;
  c2_db_A = c2_sq_y;
  c2_ivb_x = c2_db_A;
  c2_jvb_x = c2_ivb_x;
  c2_tq_y = c2_jvb_x / 100000.0;
  c2_kvb_x = c2_theta_4;
  c2_lvb_x = c2_kvb_x;
  c2_lvb_x = muDoubleScalarCos(c2_lvb_x);
  c2_qp_b = c2_lvb_x;
  c2_uq_y = 93.0 * c2_qp_b;
  c2_mvb_x = c2_theta_2;
  c2_nvb_x = c2_mvb_x;
  c2_nvb_x = muDoubleScalarCos(c2_nvb_x);
  c2_ovb_x = c2_theta_1;
  c2_pvb_x = c2_ovb_x;
  c2_pvb_x = muDoubleScalarSin(c2_pvb_x);
  c2_mo_a = c2_nvb_x;
  c2_rp_b = c2_pvb_x;
  c2_vq_y = c2_mo_a * c2_rp_b;
  c2_qvb_x = c2_theta_3;
  c2_rvb_x = c2_qvb_x;
  c2_rvb_x = muDoubleScalarSin(c2_rvb_x);
  c2_no_a = c2_vq_y;
  c2_sp_b = c2_rvb_x;
  c2_wq_y = c2_no_a * c2_sp_b;
  c2_svb_x = c2_theta_3;
  c2_tvb_x = c2_svb_x;
  c2_tvb_x = muDoubleScalarCos(c2_tvb_x);
  c2_uvb_x = c2_theta_1;
  c2_vvb_x = c2_uvb_x;
  c2_vvb_x = muDoubleScalarSin(c2_vvb_x);
  c2_oo_a = c2_tvb_x;
  c2_tp_b = c2_vvb_x;
  c2_xq_y = c2_oo_a * c2_tp_b;
  c2_wvb_x = c2_theta_2;
  c2_xvb_x = c2_wvb_x;
  c2_xvb_x = muDoubleScalarSin(c2_xvb_x);
  c2_po_a = c2_xq_y;
  c2_up_b = c2_xvb_x;
  c2_yq_y = c2_po_a * c2_up_b;
  c2_qo_a = c2_uq_y;
  c2_vp_b = c2_wq_y + c2_yq_y;
  c2_ar_y = c2_qo_a * c2_vp_b;
  c2_eb_A = c2_ar_y;
  c2_yvb_x = c2_eb_A;
  c2_awb_x = c2_yvb_x;
  c2_br_y = c2_awb_x / 1000.0;
  c2_bwb_x = c2_theta_2;
  c2_cwb_x = c2_bwb_x;
  c2_cwb_x = muDoubleScalarCos(c2_cwb_x);
  c2_wp_b = c2_cwb_x;
  c2_cr_y = 17.0 * c2_wp_b;
  c2_dwb_x = c2_theta_1;
  c2_ewb_x = c2_dwb_x;
  c2_ewb_x = muDoubleScalarSin(c2_ewb_x);
  c2_ro_a = c2_cr_y;
  c2_xp_b = c2_ewb_x;
  c2_dr_y = c2_ro_a * c2_xp_b;
  c2_fb_A = c2_dr_y;
  c2_fwb_x = c2_fb_A;
  c2_gwb_x = c2_fwb_x;
  c2_er_y = c2_gwb_x / 40.0;
  c2_hwb_x = c2_theta_1;
  c2_iwb_x = c2_hwb_x;
  c2_iwb_x = muDoubleScalarCos(c2_iwb_x);
  c2_yp_b = c2_iwb_x;
  c2_fr_y = 109.0 * c2_yp_b;
  c2_gb_A = c2_fr_y;
  c2_jwb_x = c2_gb_A;
  c2_kwb_x = c2_jwb_x;
  c2_gr_y = c2_kwb_x / 1000.0;
  c2_lwb_x = c2_theta_4;
  c2_mwb_x = c2_lwb_x;
  c2_mwb_x = muDoubleScalarSin(c2_mwb_x);
  c2_aq_b = c2_mwb_x;
  c2_hr_y = 93.0 * c2_aq_b;
  c2_nwb_x = c2_theta_1;
  c2_owb_x = c2_nwb_x;
  c2_owb_x = muDoubleScalarSin(c2_owb_x);
  c2_pwb_x = c2_theta_2;
  c2_qwb_x = c2_pwb_x;
  c2_qwb_x = muDoubleScalarSin(c2_qwb_x);
  c2_so_a = c2_owb_x;
  c2_bq_b = c2_qwb_x;
  c2_ir_y = c2_so_a * c2_bq_b;
  c2_rwb_x = c2_theta_3;
  c2_swb_x = c2_rwb_x;
  c2_swb_x = muDoubleScalarSin(c2_swb_x);
  c2_to_a = c2_ir_y;
  c2_cq_b = c2_swb_x;
  c2_jr_y = c2_to_a * c2_cq_b;
  c2_twb_x = c2_theta_2;
  c2_uwb_x = c2_twb_x;
  c2_uwb_x = muDoubleScalarCos(c2_uwb_x);
  c2_vwb_x = c2_theta_3;
  c2_wwb_x = c2_vwb_x;
  c2_wwb_x = muDoubleScalarCos(c2_wwb_x);
  c2_uo_a = c2_uwb_x;
  c2_dq_b = c2_wwb_x;
  c2_kr_y = c2_uo_a * c2_dq_b;
  c2_xwb_x = c2_theta_1;
  c2_ywb_x = c2_xwb_x;
  c2_ywb_x = muDoubleScalarSin(c2_ywb_x);
  c2_vo_a = c2_kr_y;
  c2_eq_b = c2_ywb_x;
  c2_lr_y = c2_vo_a * c2_eq_b;
  c2_wo_a = c2_hr_y;
  c2_fq_b = c2_jr_y - c2_lr_y;
  c2_mr_y = c2_wo_a * c2_fq_b;
  c2_hb_A = c2_mr_y;
  c2_axb_x = c2_hb_A;
  c2_bxb_x = c2_axb_x;
  c2_nr_y = c2_bxb_x / 1000.0;
  c2_cxb_x = c2_theta_1;
  c2_dxb_x = c2_cxb_x;
  c2_dxb_x = muDoubleScalarSin(c2_dxb_x);
  c2_gq_b = c2_dxb_x;
  c2_or_y = 39243.0 * c2_gq_b;
  c2_exb_x = c2_theta_2;
  c2_fxb_x = c2_exb_x;
  c2_fxb_x = muDoubleScalarSin(c2_fxb_x);
  c2_xo_a = c2_or_y;
  c2_hq_b = c2_fxb_x;
  c2_pr_y = c2_xo_a * c2_hq_b;
  c2_gxb_x = c2_theta_3;
  c2_hxb_x = c2_gxb_x;
  c2_hxb_x = muDoubleScalarSin(c2_hxb_x);
  c2_yo_a = c2_pr_y;
  c2_iq_b = c2_hxb_x;
  c2_qr_y = c2_yo_a * c2_iq_b;
  c2_ib_A = c2_qr_y;
  c2_ixb_x = c2_ib_A;
  c2_jxb_x = c2_ixb_x;
  c2_rr_y = c2_jxb_x / 100000.0;
  c2_kxb_x = c2_theta_2;
  c2_lxb_x = c2_kxb_x;
  c2_lxb_x = muDoubleScalarCos(c2_lxb_x);
  c2_jq_b = c2_lxb_x;
  c2_sr_y = 39243.0 * c2_jq_b;
  c2_mxb_x = c2_theta_3;
  c2_nxb_x = c2_mxb_x;
  c2_nxb_x = muDoubleScalarCos(c2_nxb_x);
  c2_ap_a = c2_sr_y;
  c2_kq_b = c2_nxb_x;
  c2_tr_y = c2_ap_a * c2_kq_b;
  c2_oxb_x = c2_theta_1;
  c2_pxb_x = c2_oxb_x;
  c2_pxb_x = muDoubleScalarSin(c2_pxb_x);
  c2_bp_a = c2_tr_y;
  c2_lq_b = c2_pxb_x;
  c2_ur_y = c2_bp_a * c2_lq_b;
  c2_jb_A = c2_ur_y;
  c2_qxb_x = c2_jb_A;
  c2_rxb_x = c2_qxb_x;
  c2_vr_y = c2_rxb_x / 100000.0;
  c2_sxb_x = c2_theta_4;
  c2_txb_x = c2_sxb_x;
  c2_txb_x = muDoubleScalarSin(c2_txb_x);
  c2_mq_b = c2_txb_x;
  c2_wr_y = 93.0 * c2_mq_b;
  c2_uxb_x = c2_theta_2;
  c2_vxb_x = c2_uxb_x;
  c2_vxb_x = muDoubleScalarCos(c2_vxb_x);
  c2_wxb_x = c2_theta_3;
  c2_xxb_x = c2_wxb_x;
  c2_xxb_x = muDoubleScalarSin(c2_xxb_x);
  c2_cp_a = c2_vxb_x;
  c2_nq_b = c2_xxb_x;
  c2_xr_y = c2_cp_a * c2_nq_b;
  c2_yxb_x = c2_theta_3;
  c2_ayb_x = c2_yxb_x;
  c2_ayb_x = muDoubleScalarCos(c2_ayb_x);
  c2_byb_x = c2_theta_2;
  c2_cyb_x = c2_byb_x;
  c2_cyb_x = muDoubleScalarSin(c2_cyb_x);
  c2_dp_a = c2_ayb_x;
  c2_oq_b = c2_cyb_x;
  c2_yr_y = c2_dp_a * c2_oq_b;
  c2_ep_a = c2_wr_y;
  c2_pq_b = c2_xr_y + c2_yr_y;
  c2_as_y = c2_ep_a * c2_pq_b;
  c2_kb_A = c2_as_y;
  c2_dyb_x = c2_kb_A;
  c2_eyb_x = c2_dyb_x;
  c2_bs_y = c2_eyb_x / 1000.0;
  c2_fyb_x = c2_theta_2;
  c2_gyb_x = c2_fyb_x;
  c2_gyb_x = muDoubleScalarCos(c2_gyb_x);
  c2_qq_b = c2_gyb_x;
  c2_cs_y = 39243.0 * c2_qq_b;
  c2_hyb_x = c2_theta_3;
  c2_iyb_x = c2_hyb_x;
  c2_iyb_x = muDoubleScalarSin(c2_iyb_x);
  c2_fp_a = c2_cs_y;
  c2_rq_b = c2_iyb_x;
  c2_ds_y = c2_fp_a * c2_rq_b;
  c2_lb_A = c2_ds_y;
  c2_jyb_x = c2_lb_A;
  c2_kyb_x = c2_jyb_x;
  c2_es_y = c2_kyb_x / 100000.0;
  c2_lyb_x = c2_theta_3;
  c2_myb_x = c2_lyb_x;
  c2_myb_x = muDoubleScalarCos(c2_myb_x);
  c2_sq_b = c2_myb_x;
  c2_fs_y = 39243.0 * c2_sq_b;
  c2_nyb_x = c2_theta_2;
  c2_oyb_x = c2_nyb_x;
  c2_oyb_x = muDoubleScalarSin(c2_oyb_x);
  c2_gp_a = c2_fs_y;
  c2_tq_b = c2_oyb_x;
  c2_gs_y = c2_gp_a * c2_tq_b;
  c2_mb_A = c2_gs_y;
  c2_pyb_x = c2_mb_A;
  c2_qyb_x = c2_pyb_x;
  c2_hs_y = c2_qyb_x / 100000.0;
  c2_ryb_x = c2_theta_4;
  c2_syb_x = c2_ryb_x;
  c2_syb_x = muDoubleScalarCos(c2_syb_x);
  c2_uq_b = c2_syb_x;
  c2_is_y = 93.0 * c2_uq_b;
  c2_tyb_x = c2_theta_2;
  c2_uyb_x = c2_tyb_x;
  c2_uyb_x = muDoubleScalarCos(c2_uyb_x);
  c2_vyb_x = c2_theta_3;
  c2_wyb_x = c2_vyb_x;
  c2_wyb_x = muDoubleScalarCos(c2_wyb_x);
  c2_hp_a = c2_uyb_x;
  c2_vq_b = c2_wyb_x;
  c2_js_y = c2_hp_a * c2_vq_b;
  c2_xyb_x = c2_theta_2;
  c2_yyb_x = c2_xyb_x;
  c2_yyb_x = muDoubleScalarSin(c2_yyb_x);
  c2_aac_x = c2_theta_3;
  c2_bac_x = c2_aac_x;
  c2_bac_x = muDoubleScalarSin(c2_bac_x);
  c2_ip_a = c2_yyb_x;
  c2_wq_b = c2_bac_x;
  c2_ks_y = c2_ip_a * c2_wq_b;
  c2_jp_a = c2_is_y;
  c2_xq_b = c2_js_y - c2_ks_y;
  c2_ls_y = c2_jp_a * c2_xq_b;
  c2_nb_A = c2_ls_y;
  c2_cac_x = c2_nb_A;
  c2_dac_x = c2_cac_x;
  c2_ms_y = c2_dac_x / 1000.0;
  c2_eac_x = c2_theta_2;
  c2_fac_x = c2_eac_x;
  c2_fac_x = muDoubleScalarSin(c2_fac_x);
  c2_yq_b = c2_fac_x;
  c2_ns_y = 17.0 * c2_yq_b;
  c2_ob_A = c2_ns_y;
  c2_gac_x = c2_ob_A;
  c2_hac_x = c2_gac_x;
  c2_os_y = c2_hac_x / 40.0;
  c2_d5[0] = ((((c2_tp_y - c2_wp_y) + c2_eq_y) - c2_lq_y) + c2_pq_y) - c2_tq_y;
  c2_d5[1] = ((((c2_br_y - c2_er_y) - c2_gr_y) - c2_nr_y) + c2_rr_y) - c2_vr_y;
  c2_d5[2] = ((((c2_bs_y - c2_es_y) - c2_hs_y) - c2_ms_y) - c2_os_y) + 0.0892;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
  c2_iac_x = c2_theta_1;
  c2_jac_x = c2_iac_x;
  c2_jac_x = muDoubleScalarSin(c2_jac_x);
  c2_ar_b = c2_jac_x;
  c2_ps_y = 109.0 * c2_ar_b;
  c2_pb_A = c2_ps_y;
  c2_kac_x = c2_pb_A;
  c2_lac_x = c2_kac_x;
  c2_qs_y = c2_lac_x / 1000.0;
  c2_mac_x = c2_theta_1;
  c2_nac_x = c2_mac_x;
  c2_nac_x = muDoubleScalarCos(c2_nac_x);
  c2_br_b = c2_nac_x;
  c2_rs_y = 17.0 * c2_br_b;
  c2_oac_x = c2_theta_2;
  c2_pac_x = c2_oac_x;
  c2_pac_x = muDoubleScalarCos(c2_pac_x);
  c2_kp_a = c2_rs_y;
  c2_cr_b = c2_pac_x;
  c2_ss_y = c2_kp_a * c2_cr_b;
  c2_qb_A = c2_ss_y;
  c2_qac_x = c2_qb_A;
  c2_rac_x = c2_qac_x;
  c2_ts_y = c2_rac_x / 40.0;
  c2_sac_x = c2_theta_5;
  c2_tac_x = c2_sac_x;
  c2_tac_x = muDoubleScalarCos(c2_tac_x);
  c2_dr_b = c2_tac_x;
  c2_us_y = 41.0 * c2_dr_b;
  c2_uac_x = c2_theta_1;
  c2_vac_x = c2_uac_x;
  c2_vac_x = muDoubleScalarSin(c2_vac_x);
  c2_lp_a = c2_us_y;
  c2_er_b = c2_vac_x;
  c2_vs_y = c2_lp_a * c2_er_b;
  c2_rb_A = c2_vs_y;
  c2_wac_x = c2_rb_A;
  c2_xac_x = c2_wac_x;
  c2_ws_y = c2_xac_x / 500.0;
  c2_yac_x = c2_theta_4;
  c2_abc_x = c2_yac_x;
  c2_abc_x = muDoubleScalarCos(c2_abc_x);
  c2_fr_b = c2_abc_x;
  c2_xs_y = 93.0 * c2_fr_b;
  c2_bbc_x = c2_theta_1;
  c2_cbc_x = c2_bbc_x;
  c2_cbc_x = muDoubleScalarCos(c2_cbc_x);
  c2_dbc_x = c2_theta_2;
  c2_ebc_x = c2_dbc_x;
  c2_ebc_x = muDoubleScalarCos(c2_ebc_x);
  c2_mp_a = c2_cbc_x;
  c2_gr_b = c2_ebc_x;
  c2_ys_y = c2_mp_a * c2_gr_b;
  c2_fbc_x = c2_theta_3;
  c2_gbc_x = c2_fbc_x;
  c2_gbc_x = muDoubleScalarSin(c2_gbc_x);
  c2_np_a = c2_ys_y;
  c2_hr_b = c2_gbc_x;
  c2_at_y = c2_np_a * c2_hr_b;
  c2_hbc_x = c2_theta_1;
  c2_ibc_x = c2_hbc_x;
  c2_ibc_x = muDoubleScalarCos(c2_ibc_x);
  c2_jbc_x = c2_theta_3;
  c2_kbc_x = c2_jbc_x;
  c2_kbc_x = muDoubleScalarCos(c2_kbc_x);
  c2_op_a = c2_ibc_x;
  c2_ir_b = c2_kbc_x;
  c2_bt_y = c2_op_a * c2_ir_b;
  c2_lbc_x = c2_theta_2;
  c2_mbc_x = c2_lbc_x;
  c2_mbc_x = muDoubleScalarSin(c2_mbc_x);
  c2_pp_a = c2_bt_y;
  c2_jr_b = c2_mbc_x;
  c2_ct_y = c2_pp_a * c2_jr_b;
  c2_qp_a = c2_xs_y;
  c2_kr_b = c2_at_y + c2_ct_y;
  c2_dt_y = c2_qp_a * c2_kr_b;
  c2_sb_A = c2_dt_y;
  c2_nbc_x = c2_sb_A;
  c2_obc_x = c2_nbc_x;
  c2_et_y = c2_obc_x / 1000.0;
  c2_pbc_x = c2_theta_4;
  c2_qbc_x = c2_pbc_x;
  c2_qbc_x = muDoubleScalarSin(c2_qbc_x);
  c2_lr_b = c2_qbc_x;
  c2_ft_y = 93.0 * c2_lr_b;
  c2_rbc_x = c2_theta_1;
  c2_sbc_x = c2_rbc_x;
  c2_sbc_x = muDoubleScalarCos(c2_sbc_x);
  c2_tbc_x = c2_theta_2;
  c2_ubc_x = c2_tbc_x;
  c2_ubc_x = muDoubleScalarSin(c2_ubc_x);
  c2_rp_a = c2_sbc_x;
  c2_mr_b = c2_ubc_x;
  c2_gt_y = c2_rp_a * c2_mr_b;
  c2_vbc_x = c2_theta_3;
  c2_wbc_x = c2_vbc_x;
  c2_wbc_x = muDoubleScalarSin(c2_wbc_x);
  c2_sp_a = c2_gt_y;
  c2_nr_b = c2_wbc_x;
  c2_ht_y = c2_sp_a * c2_nr_b;
  c2_xbc_x = c2_theta_1;
  c2_ybc_x = c2_xbc_x;
  c2_ybc_x = muDoubleScalarCos(c2_ybc_x);
  c2_acc_x = c2_theta_2;
  c2_bcc_x = c2_acc_x;
  c2_bcc_x = muDoubleScalarCos(c2_bcc_x);
  c2_tp_a = c2_ybc_x;
  c2_or_b = c2_bcc_x;
  c2_it_y = c2_tp_a * c2_or_b;
  c2_ccc_x = c2_theta_3;
  c2_dcc_x = c2_ccc_x;
  c2_dcc_x = muDoubleScalarCos(c2_dcc_x);
  c2_up_a = c2_it_y;
  c2_pr_b = c2_dcc_x;
  c2_jt_y = c2_up_a * c2_pr_b;
  c2_vp_a = c2_ft_y;
  c2_qr_b = c2_ht_y - c2_jt_y;
  c2_kt_y = c2_vp_a * c2_qr_b;
  c2_tb_A = c2_kt_y;
  c2_ecc_x = c2_tb_A;
  c2_fcc_x = c2_ecc_x;
  c2_lt_y = c2_fcc_x / 1000.0;
  c2_gcc_x = c2_theta_5;
  c2_hcc_x = c2_gcc_x;
  c2_hcc_x = muDoubleScalarSin(c2_hcc_x);
  c2_rr_b = c2_hcc_x;
  c2_mt_y = 41.0 * c2_rr_b;
  c2_icc_x = c2_theta_4;
  c2_jcc_x = c2_icc_x;
  c2_jcc_x = muDoubleScalarCos(c2_jcc_x);
  c2_kcc_x = c2_theta_1;
  c2_lcc_x = c2_kcc_x;
  c2_lcc_x = muDoubleScalarCos(c2_lcc_x);
  c2_mcc_x = c2_theta_2;
  c2_ncc_x = c2_mcc_x;
  c2_ncc_x = muDoubleScalarSin(c2_ncc_x);
  c2_wp_a = c2_lcc_x;
  c2_sr_b = c2_ncc_x;
  c2_nt_y = c2_wp_a * c2_sr_b;
  c2_occ_x = c2_theta_3;
  c2_pcc_x = c2_occ_x;
  c2_pcc_x = muDoubleScalarSin(c2_pcc_x);
  c2_xp_a = c2_nt_y;
  c2_tr_b = c2_pcc_x;
  c2_ot_y = c2_xp_a * c2_tr_b;
  c2_qcc_x = c2_theta_1;
  c2_rcc_x = c2_qcc_x;
  c2_rcc_x = muDoubleScalarCos(c2_rcc_x);
  c2_scc_x = c2_theta_2;
  c2_tcc_x = c2_scc_x;
  c2_tcc_x = muDoubleScalarCos(c2_tcc_x);
  c2_yp_a = c2_rcc_x;
  c2_ur_b = c2_tcc_x;
  c2_pt_y = c2_yp_a * c2_ur_b;
  c2_ucc_x = c2_theta_3;
  c2_vcc_x = c2_ucc_x;
  c2_vcc_x = muDoubleScalarCos(c2_vcc_x);
  c2_aq_a = c2_pt_y;
  c2_vr_b = c2_vcc_x;
  c2_qt_y = c2_aq_a * c2_vr_b;
  c2_bq_a = c2_jcc_x;
  c2_wr_b = c2_ot_y - c2_qt_y;
  c2_rt_y = c2_bq_a * c2_wr_b;
  c2_wcc_x = c2_theta_4;
  c2_xcc_x = c2_wcc_x;
  c2_xcc_x = muDoubleScalarSin(c2_xcc_x);
  c2_ycc_x = c2_theta_1;
  c2_adc_x = c2_ycc_x;
  c2_adc_x = muDoubleScalarCos(c2_adc_x);
  c2_bdc_x = c2_theta_2;
  c2_cdc_x = c2_bdc_x;
  c2_cdc_x = muDoubleScalarCos(c2_cdc_x);
  c2_cq_a = c2_adc_x;
  c2_xr_b = c2_cdc_x;
  c2_st_y = c2_cq_a * c2_xr_b;
  c2_ddc_x = c2_theta_3;
  c2_edc_x = c2_ddc_x;
  c2_edc_x = muDoubleScalarSin(c2_edc_x);
  c2_dq_a = c2_st_y;
  c2_yr_b = c2_edc_x;
  c2_tt_y = c2_dq_a * c2_yr_b;
  c2_fdc_x = c2_theta_1;
  c2_gdc_x = c2_fdc_x;
  c2_gdc_x = muDoubleScalarCos(c2_gdc_x);
  c2_hdc_x = c2_theta_3;
  c2_idc_x = c2_hdc_x;
  c2_idc_x = muDoubleScalarCos(c2_idc_x);
  c2_eq_a = c2_gdc_x;
  c2_as_b = c2_idc_x;
  c2_ut_y = c2_eq_a * c2_as_b;
  c2_jdc_x = c2_theta_2;
  c2_kdc_x = c2_jdc_x;
  c2_kdc_x = muDoubleScalarSin(c2_kdc_x);
  c2_fq_a = c2_ut_y;
  c2_bs_b = c2_kdc_x;
  c2_vt_y = c2_fq_a * c2_bs_b;
  c2_gq_a = c2_xcc_x;
  c2_cs_b = c2_tt_y + c2_vt_y;
  c2_wt_y = c2_gq_a * c2_cs_b;
  c2_hq_a = c2_mt_y;
  c2_ds_b = c2_rt_y + c2_wt_y;
  c2_xt_y = c2_hq_a * c2_ds_b;
  c2_ub_A = c2_xt_y;
  c2_ldc_x = c2_ub_A;
  c2_mdc_x = c2_ldc_x;
  c2_yt_y = c2_mdc_x / 500.0;
  c2_ndc_x = c2_theta_1;
  c2_odc_x = c2_ndc_x;
  c2_odc_x = muDoubleScalarCos(c2_odc_x);
  c2_es_b = c2_odc_x;
  c2_au_y = 39243.0 * c2_es_b;
  c2_pdc_x = c2_theta_2;
  c2_qdc_x = c2_pdc_x;
  c2_qdc_x = muDoubleScalarSin(c2_qdc_x);
  c2_iq_a = c2_au_y;
  c2_fs_b = c2_qdc_x;
  c2_bu_y = c2_iq_a * c2_fs_b;
  c2_rdc_x = c2_theta_3;
  c2_sdc_x = c2_rdc_x;
  c2_sdc_x = muDoubleScalarSin(c2_sdc_x);
  c2_jq_a = c2_bu_y;
  c2_gs_b = c2_sdc_x;
  c2_cu_y = c2_jq_a * c2_gs_b;
  c2_vb_A = c2_cu_y;
  c2_tdc_x = c2_vb_A;
  c2_udc_x = c2_tdc_x;
  c2_du_y = c2_udc_x / 100000.0;
  c2_vdc_x = c2_theta_1;
  c2_wdc_x = c2_vdc_x;
  c2_wdc_x = muDoubleScalarCos(c2_wdc_x);
  c2_hs_b = c2_wdc_x;
  c2_eu_y = 39243.0 * c2_hs_b;
  c2_xdc_x = c2_theta_2;
  c2_ydc_x = c2_xdc_x;
  c2_ydc_x = muDoubleScalarCos(c2_ydc_x);
  c2_kq_a = c2_eu_y;
  c2_is_b = c2_ydc_x;
  c2_fu_y = c2_kq_a * c2_is_b;
  c2_aec_x = c2_theta_3;
  c2_bec_x = c2_aec_x;
  c2_bec_x = muDoubleScalarCos(c2_bec_x);
  c2_lq_a = c2_fu_y;
  c2_js_b = c2_bec_x;
  c2_gu_y = c2_lq_a * c2_js_b;
  c2_wb_A = c2_gu_y;
  c2_cec_x = c2_wb_A;
  c2_dec_x = c2_cec_x;
  c2_hu_y = c2_dec_x / 100000.0;
  c2_eec_x = c2_theta_4;
  c2_fec_x = c2_eec_x;
  c2_fec_x = muDoubleScalarCos(c2_fec_x);
  c2_ks_b = c2_fec_x;
  c2_iu_y = 93.0 * c2_ks_b;
  c2_gec_x = c2_theta_2;
  c2_hec_x = c2_gec_x;
  c2_hec_x = muDoubleScalarCos(c2_hec_x);
  c2_iec_x = c2_theta_1;
  c2_jec_x = c2_iec_x;
  c2_jec_x = muDoubleScalarSin(c2_jec_x);
  c2_mq_a = c2_hec_x;
  c2_ls_b = c2_jec_x;
  c2_ju_y = c2_mq_a * c2_ls_b;
  c2_kec_x = c2_theta_3;
  c2_lec_x = c2_kec_x;
  c2_lec_x = muDoubleScalarSin(c2_lec_x);
  c2_nq_a = c2_ju_y;
  c2_ms_b = c2_lec_x;
  c2_ku_y = c2_nq_a * c2_ms_b;
  c2_mec_x = c2_theta_3;
  c2_nec_x = c2_mec_x;
  c2_nec_x = muDoubleScalarCos(c2_nec_x);
  c2_oec_x = c2_theta_1;
  c2_pec_x = c2_oec_x;
  c2_pec_x = muDoubleScalarSin(c2_pec_x);
  c2_oq_a = c2_nec_x;
  c2_ns_b = c2_pec_x;
  c2_lu_y = c2_oq_a * c2_ns_b;
  c2_qec_x = c2_theta_2;
  c2_rec_x = c2_qec_x;
  c2_rec_x = muDoubleScalarSin(c2_rec_x);
  c2_pq_a = c2_lu_y;
  c2_os_b = c2_rec_x;
  c2_mu_y = c2_pq_a * c2_os_b;
  c2_qq_a = c2_iu_y;
  c2_ps_b = c2_ku_y + c2_mu_y;
  c2_nu_y = c2_qq_a * c2_ps_b;
  c2_xb_A = c2_nu_y;
  c2_sec_x = c2_xb_A;
  c2_tec_x = c2_sec_x;
  c2_ou_y = c2_tec_x / 1000.0;
  c2_uec_x = c2_theta_1;
  c2_vec_x = c2_uec_x;
  c2_vec_x = muDoubleScalarCos(c2_vec_x);
  c2_qs_b = c2_vec_x;
  c2_pu_y = 41.0 * c2_qs_b;
  c2_wec_x = c2_theta_5;
  c2_xec_x = c2_wec_x;
  c2_xec_x = muDoubleScalarCos(c2_xec_x);
  c2_rq_a = c2_pu_y;
  c2_rs_b = c2_xec_x;
  c2_qu_y = c2_rq_a * c2_rs_b;
  c2_yb_A = c2_qu_y;
  c2_yec_x = c2_yb_A;
  c2_afc_x = c2_yec_x;
  c2_ru_y = c2_afc_x / 500.0;
  c2_bfc_x = c2_theta_2;
  c2_cfc_x = c2_bfc_x;
  c2_cfc_x = muDoubleScalarCos(c2_cfc_x);
  c2_ss_b = c2_cfc_x;
  c2_su_y = 17.0 * c2_ss_b;
  c2_dfc_x = c2_theta_1;
  c2_efc_x = c2_dfc_x;
  c2_efc_x = muDoubleScalarSin(c2_efc_x);
  c2_sq_a = c2_su_y;
  c2_ts_b = c2_efc_x;
  c2_tu_y = c2_sq_a * c2_ts_b;
  c2_ac_A = c2_tu_y;
  c2_ffc_x = c2_ac_A;
  c2_gfc_x = c2_ffc_x;
  c2_uu_y = c2_gfc_x / 40.0;
  c2_hfc_x = c2_theta_1;
  c2_ifc_x = c2_hfc_x;
  c2_ifc_x = muDoubleScalarCos(c2_ifc_x);
  c2_us_b = c2_ifc_x;
  c2_vu_y = 109.0 * c2_us_b;
  c2_bc_A = c2_vu_y;
  c2_jfc_x = c2_bc_A;
  c2_kfc_x = c2_jfc_x;
  c2_wu_y = c2_kfc_x / 1000.0;
  c2_lfc_x = c2_theta_4;
  c2_mfc_x = c2_lfc_x;
  c2_mfc_x = muDoubleScalarSin(c2_mfc_x);
  c2_vs_b = c2_mfc_x;
  c2_xu_y = 93.0 * c2_vs_b;
  c2_nfc_x = c2_theta_1;
  c2_ofc_x = c2_nfc_x;
  c2_ofc_x = muDoubleScalarSin(c2_ofc_x);
  c2_pfc_x = c2_theta_2;
  c2_qfc_x = c2_pfc_x;
  c2_qfc_x = muDoubleScalarSin(c2_qfc_x);
  c2_tq_a = c2_ofc_x;
  c2_ws_b = c2_qfc_x;
  c2_yu_y = c2_tq_a * c2_ws_b;
  c2_rfc_x = c2_theta_3;
  c2_sfc_x = c2_rfc_x;
  c2_sfc_x = muDoubleScalarSin(c2_sfc_x);
  c2_uq_a = c2_yu_y;
  c2_xs_b = c2_sfc_x;
  c2_av_y = c2_uq_a * c2_xs_b;
  c2_tfc_x = c2_theta_2;
  c2_ufc_x = c2_tfc_x;
  c2_ufc_x = muDoubleScalarCos(c2_ufc_x);
  c2_vfc_x = c2_theta_3;
  c2_wfc_x = c2_vfc_x;
  c2_wfc_x = muDoubleScalarCos(c2_wfc_x);
  c2_vq_a = c2_ufc_x;
  c2_ys_b = c2_wfc_x;
  c2_bv_y = c2_vq_a * c2_ys_b;
  c2_xfc_x = c2_theta_1;
  c2_yfc_x = c2_xfc_x;
  c2_yfc_x = muDoubleScalarSin(c2_yfc_x);
  c2_wq_a = c2_bv_y;
  c2_at_b = c2_yfc_x;
  c2_cv_y = c2_wq_a * c2_at_b;
  c2_xq_a = c2_xu_y;
  c2_bt_b = c2_av_y - c2_cv_y;
  c2_dv_y = c2_xq_a * c2_bt_b;
  c2_cc_A = c2_dv_y;
  c2_agc_x = c2_cc_A;
  c2_bgc_x = c2_agc_x;
  c2_ev_y = c2_bgc_x / 1000.0;
  c2_cgc_x = c2_theta_5;
  c2_dgc_x = c2_cgc_x;
  c2_dgc_x = muDoubleScalarSin(c2_dgc_x);
  c2_ct_b = c2_dgc_x;
  c2_fv_y = 41.0 * c2_ct_b;
  c2_egc_x = c2_theta_4;
  c2_fgc_x = c2_egc_x;
  c2_fgc_x = muDoubleScalarCos(c2_fgc_x);
  c2_ggc_x = c2_theta_1;
  c2_hgc_x = c2_ggc_x;
  c2_hgc_x = muDoubleScalarSin(c2_hgc_x);
  c2_igc_x = c2_theta_2;
  c2_jgc_x = c2_igc_x;
  c2_jgc_x = muDoubleScalarSin(c2_jgc_x);
  c2_yq_a = c2_hgc_x;
  c2_dt_b = c2_jgc_x;
  c2_gv_y = c2_yq_a * c2_dt_b;
  c2_kgc_x = c2_theta_3;
  c2_lgc_x = c2_kgc_x;
  c2_lgc_x = muDoubleScalarSin(c2_lgc_x);
  c2_ar_a = c2_gv_y;
  c2_et_b = c2_lgc_x;
  c2_hv_y = c2_ar_a * c2_et_b;
  c2_mgc_x = c2_theta_2;
  c2_ngc_x = c2_mgc_x;
  c2_ngc_x = muDoubleScalarCos(c2_ngc_x);
  c2_ogc_x = c2_theta_3;
  c2_pgc_x = c2_ogc_x;
  c2_pgc_x = muDoubleScalarCos(c2_pgc_x);
  c2_br_a = c2_ngc_x;
  c2_ft_b = c2_pgc_x;
  c2_iv_y = c2_br_a * c2_ft_b;
  c2_qgc_x = c2_theta_1;
  c2_rgc_x = c2_qgc_x;
  c2_rgc_x = muDoubleScalarSin(c2_rgc_x);
  c2_cr_a = c2_iv_y;
  c2_gt_b = c2_rgc_x;
  c2_jv_y = c2_cr_a * c2_gt_b;
  c2_dr_a = c2_fgc_x;
  c2_ht_b = c2_hv_y - c2_jv_y;
  c2_kv_y = c2_dr_a * c2_ht_b;
  c2_sgc_x = c2_theta_4;
  c2_tgc_x = c2_sgc_x;
  c2_tgc_x = muDoubleScalarSin(c2_tgc_x);
  c2_ugc_x = c2_theta_2;
  c2_vgc_x = c2_ugc_x;
  c2_vgc_x = muDoubleScalarCos(c2_vgc_x);
  c2_wgc_x = c2_theta_1;
  c2_xgc_x = c2_wgc_x;
  c2_xgc_x = muDoubleScalarSin(c2_xgc_x);
  c2_er_a = c2_vgc_x;
  c2_it_b = c2_xgc_x;
  c2_lv_y = c2_er_a * c2_it_b;
  c2_ygc_x = c2_theta_3;
  c2_ahc_x = c2_ygc_x;
  c2_ahc_x = muDoubleScalarSin(c2_ahc_x);
  c2_fr_a = c2_lv_y;
  c2_jt_b = c2_ahc_x;
  c2_mv_y = c2_fr_a * c2_jt_b;
  c2_bhc_x = c2_theta_3;
  c2_chc_x = c2_bhc_x;
  c2_chc_x = muDoubleScalarCos(c2_chc_x);
  c2_dhc_x = c2_theta_1;
  c2_ehc_x = c2_dhc_x;
  c2_ehc_x = muDoubleScalarSin(c2_ehc_x);
  c2_gr_a = c2_chc_x;
  c2_kt_b = c2_ehc_x;
  c2_nv_y = c2_gr_a * c2_kt_b;
  c2_fhc_x = c2_theta_2;
  c2_ghc_x = c2_fhc_x;
  c2_ghc_x = muDoubleScalarSin(c2_ghc_x);
  c2_hr_a = c2_nv_y;
  c2_lt_b = c2_ghc_x;
  c2_ov_y = c2_hr_a * c2_lt_b;
  c2_ir_a = c2_tgc_x;
  c2_mt_b = c2_mv_y + c2_ov_y;
  c2_pv_y = c2_ir_a * c2_mt_b;
  c2_jr_a = c2_fv_y;
  c2_nt_b = c2_kv_y + c2_pv_y;
  c2_qv_y = c2_jr_a * c2_nt_b;
  c2_dc_A = c2_qv_y;
  c2_hhc_x = c2_dc_A;
  c2_ihc_x = c2_hhc_x;
  c2_rv_y = c2_ihc_x / 500.0;
  c2_jhc_x = c2_theta_1;
  c2_khc_x = c2_jhc_x;
  c2_khc_x = muDoubleScalarSin(c2_khc_x);
  c2_ot_b = c2_khc_x;
  c2_sv_y = 39243.0 * c2_ot_b;
  c2_lhc_x = c2_theta_2;
  c2_mhc_x = c2_lhc_x;
  c2_mhc_x = muDoubleScalarSin(c2_mhc_x);
  c2_kr_a = c2_sv_y;
  c2_pt_b = c2_mhc_x;
  c2_tv_y = c2_kr_a * c2_pt_b;
  c2_nhc_x = c2_theta_3;
  c2_ohc_x = c2_nhc_x;
  c2_ohc_x = muDoubleScalarSin(c2_ohc_x);
  c2_lr_a = c2_tv_y;
  c2_qt_b = c2_ohc_x;
  c2_uv_y = c2_lr_a * c2_qt_b;
  c2_ec_A = c2_uv_y;
  c2_phc_x = c2_ec_A;
  c2_qhc_x = c2_phc_x;
  c2_vv_y = c2_qhc_x / 100000.0;
  c2_rhc_x = c2_theta_2;
  c2_shc_x = c2_rhc_x;
  c2_shc_x = muDoubleScalarCos(c2_shc_x);
  c2_rt_b = c2_shc_x;
  c2_wv_y = 39243.0 * c2_rt_b;
  c2_thc_x = c2_theta_3;
  c2_uhc_x = c2_thc_x;
  c2_uhc_x = muDoubleScalarCos(c2_uhc_x);
  c2_mr_a = c2_wv_y;
  c2_st_b = c2_uhc_x;
  c2_xv_y = c2_mr_a * c2_st_b;
  c2_vhc_x = c2_theta_1;
  c2_whc_x = c2_vhc_x;
  c2_whc_x = muDoubleScalarSin(c2_whc_x);
  c2_nr_a = c2_xv_y;
  c2_tt_b = c2_whc_x;
  c2_yv_y = c2_nr_a * c2_tt_b;
  c2_fc_A = c2_yv_y;
  c2_xhc_x = c2_fc_A;
  c2_yhc_x = c2_xhc_x;
  c2_aw_y = c2_yhc_x / 100000.0;
  c2_aic_x = c2_theta_4;
  c2_bic_x = c2_aic_x;
  c2_bic_x = muDoubleScalarSin(c2_bic_x);
  c2_ut_b = c2_bic_x;
  c2_bw_y = 93.0 * c2_ut_b;
  c2_cic_x = c2_theta_2;
  c2_dic_x = c2_cic_x;
  c2_dic_x = muDoubleScalarCos(c2_dic_x);
  c2_eic_x = c2_theta_3;
  c2_fic_x = c2_eic_x;
  c2_fic_x = muDoubleScalarSin(c2_fic_x);
  c2_or_a = c2_dic_x;
  c2_vt_b = c2_fic_x;
  c2_cw_y = c2_or_a * c2_vt_b;
  c2_gic_x = c2_theta_3;
  c2_hic_x = c2_gic_x;
  c2_hic_x = muDoubleScalarCos(c2_hic_x);
  c2_iic_x = c2_theta_2;
  c2_jic_x = c2_iic_x;
  c2_jic_x = muDoubleScalarSin(c2_jic_x);
  c2_pr_a = c2_hic_x;
  c2_wt_b = c2_jic_x;
  c2_dw_y = c2_pr_a * c2_wt_b;
  c2_qr_a = c2_bw_y;
  c2_xt_b = c2_cw_y + c2_dw_y;
  c2_ew_y = c2_qr_a * c2_xt_b;
  c2_gc_A = c2_ew_y;
  c2_kic_x = c2_gc_A;
  c2_lic_x = c2_kic_x;
  c2_fw_y = c2_lic_x / 1000.0;
  c2_mic_x = c2_theta_2;
  c2_nic_x = c2_mic_x;
  c2_nic_x = muDoubleScalarCos(c2_nic_x);
  c2_yt_b = c2_nic_x;
  c2_gw_y = 39243.0 * c2_yt_b;
  c2_oic_x = c2_theta_3;
  c2_pic_x = c2_oic_x;
  c2_pic_x = muDoubleScalarSin(c2_pic_x);
  c2_rr_a = c2_gw_y;
  c2_au_b = c2_pic_x;
  c2_hw_y = c2_rr_a * c2_au_b;
  c2_hc_A = c2_hw_y;
  c2_qic_x = c2_hc_A;
  c2_ric_x = c2_qic_x;
  c2_iw_y = c2_ric_x / 100000.0;
  c2_sic_x = c2_theta_3;
  c2_tic_x = c2_sic_x;
  c2_tic_x = muDoubleScalarCos(c2_tic_x);
  c2_bu_b = c2_tic_x;
  c2_jw_y = 39243.0 * c2_bu_b;
  c2_uic_x = c2_theta_2;
  c2_vic_x = c2_uic_x;
  c2_vic_x = muDoubleScalarSin(c2_vic_x);
  c2_sr_a = c2_jw_y;
  c2_cu_b = c2_vic_x;
  c2_kw_y = c2_sr_a * c2_cu_b;
  c2_ic_A = c2_kw_y;
  c2_wic_x = c2_ic_A;
  c2_xic_x = c2_wic_x;
  c2_lw_y = c2_xic_x / 100000.0;
  c2_yic_x = c2_theta_5;
  c2_ajc_x = c2_yic_x;
  c2_ajc_x = muDoubleScalarSin(c2_ajc_x);
  c2_du_b = c2_ajc_x;
  c2_mw_y = 41.0 * c2_du_b;
  c2_bjc_x = c2_theta_4;
  c2_cjc_x = c2_bjc_x;
  c2_cjc_x = muDoubleScalarCos(c2_cjc_x);
  c2_djc_x = c2_theta_2;
  c2_ejc_x = c2_djc_x;
  c2_ejc_x = muDoubleScalarCos(c2_ejc_x);
  c2_fjc_x = c2_theta_3;
  c2_gjc_x = c2_fjc_x;
  c2_gjc_x = muDoubleScalarSin(c2_gjc_x);
  c2_tr_a = c2_ejc_x;
  c2_eu_b = c2_gjc_x;
  c2_nw_y = c2_tr_a * c2_eu_b;
  c2_hjc_x = c2_theta_3;
  c2_ijc_x = c2_hjc_x;
  c2_ijc_x = muDoubleScalarCos(c2_ijc_x);
  c2_jjc_x = c2_theta_2;
  c2_kjc_x = c2_jjc_x;
  c2_kjc_x = muDoubleScalarSin(c2_kjc_x);
  c2_ur_a = c2_ijc_x;
  c2_fu_b = c2_kjc_x;
  c2_ow_y = c2_ur_a * c2_fu_b;
  c2_vr_a = c2_cjc_x;
  c2_gu_b = c2_nw_y + c2_ow_y;
  c2_pw_y = c2_vr_a * c2_gu_b;
  c2_ljc_x = c2_theta_4;
  c2_mjc_x = c2_ljc_x;
  c2_mjc_x = muDoubleScalarSin(c2_mjc_x);
  c2_njc_x = c2_theta_2;
  c2_ojc_x = c2_njc_x;
  c2_ojc_x = muDoubleScalarCos(c2_ojc_x);
  c2_pjc_x = c2_theta_3;
  c2_qjc_x = c2_pjc_x;
  c2_qjc_x = muDoubleScalarCos(c2_qjc_x);
  c2_wr_a = c2_ojc_x;
  c2_hu_b = c2_qjc_x;
  c2_qw_y = c2_wr_a * c2_hu_b;
  c2_rjc_x = c2_theta_2;
  c2_sjc_x = c2_rjc_x;
  c2_sjc_x = muDoubleScalarSin(c2_sjc_x);
  c2_tjc_x = c2_theta_3;
  c2_ujc_x = c2_tjc_x;
  c2_ujc_x = muDoubleScalarSin(c2_ujc_x);
  c2_xr_a = c2_sjc_x;
  c2_iu_b = c2_ujc_x;
  c2_rw_y = c2_xr_a * c2_iu_b;
  c2_yr_a = c2_mjc_x;
  c2_ju_b = c2_qw_y - c2_rw_y;
  c2_sw_y = c2_yr_a * c2_ju_b;
  c2_as_a = c2_mw_y;
  c2_ku_b = c2_pw_y + c2_sw_y;
  c2_tw_y = c2_as_a * c2_ku_b;
  c2_jc_A = c2_tw_y;
  c2_vjc_x = c2_jc_A;
  c2_wjc_x = c2_vjc_x;
  c2_uw_y = c2_wjc_x / 500.0;
  c2_xjc_x = c2_theta_4;
  c2_yjc_x = c2_xjc_x;
  c2_yjc_x = muDoubleScalarCos(c2_yjc_x);
  c2_lu_b = c2_yjc_x;
  c2_vw_y = 93.0 * c2_lu_b;
  c2_akc_x = c2_theta_2;
  c2_bkc_x = c2_akc_x;
  c2_bkc_x = muDoubleScalarCos(c2_bkc_x);
  c2_ckc_x = c2_theta_3;
  c2_dkc_x = c2_ckc_x;
  c2_dkc_x = muDoubleScalarCos(c2_dkc_x);
  c2_bs_a = c2_bkc_x;
  c2_mu_b = c2_dkc_x;
  c2_ww_y = c2_bs_a * c2_mu_b;
  c2_ekc_x = c2_theta_2;
  c2_fkc_x = c2_ekc_x;
  c2_fkc_x = muDoubleScalarSin(c2_fkc_x);
  c2_gkc_x = c2_theta_3;
  c2_hkc_x = c2_gkc_x;
  c2_hkc_x = muDoubleScalarSin(c2_hkc_x);
  c2_cs_a = c2_fkc_x;
  c2_nu_b = c2_hkc_x;
  c2_xw_y = c2_cs_a * c2_nu_b;
  c2_ds_a = c2_vw_y;
  c2_ou_b = c2_ww_y - c2_xw_y;
  c2_yw_y = c2_ds_a * c2_ou_b;
  c2_kc_A = c2_yw_y;
  c2_ikc_x = c2_kc_A;
  c2_jkc_x = c2_ikc_x;
  c2_ax_y = c2_jkc_x / 1000.0;
  c2_kkc_x = c2_theta_2;
  c2_lkc_x = c2_kkc_x;
  c2_lkc_x = muDoubleScalarSin(c2_lkc_x);
  c2_pu_b = c2_lkc_x;
  c2_bx_y = 17.0 * c2_pu_b;
  c2_lc_A = c2_bx_y;
  c2_mkc_x = c2_lc_A;
  c2_nkc_x = c2_mkc_x;
  c2_cx_y = c2_nkc_x / 40.0;
  c2_d6[0] = ((((((c2_qs_y - c2_ts_y) + c2_ws_y) + c2_et_y) - c2_lt_y) + c2_yt_y)
              + c2_du_y) - c2_hu_y;
  c2_d6[1] = ((((((c2_ou_y - c2_ru_y) - c2_uu_y) - c2_wu_y) - c2_ev_y) + c2_rv_y)
              + c2_vv_y) - c2_aw_y;
  c2_d6[2] = (((((c2_fw_y - c2_iw_y) - c2_lw_y) - c2_uw_y) - c2_ax_y) - c2_cx_y)
    + 0.0892;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  for (c2_i29 = 0; c2_i29 < 9; c2_i29++) {
    c2_es_a[c2_i29] = c2_R1[c2_i29];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i30 = 0; c2_i30 < 3; c2_i30++) {
    c2_dx_y[c2_i30] = 0.0;
    c2_i31 = 0;
    for (c2_i32 = 0; c2_i32 < 3; c2_i32++) {
      c2_dx_y[c2_i30] += c2_es_a[c2_i31 + c2_i30] * c2_qu_b[c2_i32];
      c2_i31 += 3;
    }
  }

  for (c2_i33 = 0; c2_i33 < 3; c2_i33++) {
    c2_r0_c1[c2_i33] = c2_d1[c2_i33] + c2_dx_y[c2_i33];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
  for (c2_i34 = 0; c2_i34 < 9; c2_i34++) {
    c2_es_a[c2_i34] = c2_R2[c2_i34];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i35 = 0; c2_i35 < 3; c2_i35++) {
    c2_dx_y[c2_i35] = 0.0;
    c2_i36 = 0;
    for (c2_i37 = 0; c2_i37 < 3; c2_i37++) {
      c2_dx_y[c2_i35] += c2_es_a[c2_i36 + c2_i35] * c2_ru_b[c2_i37];
      c2_i36 += 3;
    }
  }

  for (c2_i38 = 0; c2_i38 < 3; c2_i38++) {
    c2_r0_c2[c2_i38] = c2_d2[c2_i38] + c2_dx_y[c2_i38];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
  for (c2_i39 = 0; c2_i39 < 9; c2_i39++) {
    c2_es_a[c2_i39] = c2_R3[c2_i39];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i40 = 0; c2_i40 < 3; c2_i40++) {
    c2_dx_y[c2_i40] = 0.0;
    c2_i41 = 0;
    for (c2_i42 = 0; c2_i42 < 3; c2_i42++) {
      c2_dx_y[c2_i40] += c2_es_a[c2_i41 + c2_i40] * c2_su_b[c2_i42];
      c2_i41 += 3;
    }
  }

  for (c2_i43 = 0; c2_i43 < 3; c2_i43++) {
    c2_r0_c3[c2_i43] = c2_d3[c2_i43] + c2_dx_y[c2_i43];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
  for (c2_i44 = 0; c2_i44 < 9; c2_i44++) {
    c2_es_a[c2_i44] = c2_R4[c2_i44];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i45 = 0; c2_i45 < 3; c2_i45++) {
    c2_dx_y[c2_i45] = 0.0;
    c2_i46 = 0;
    for (c2_i47 = 0; c2_i47 < 3; c2_i47++) {
      c2_dx_y[c2_i45] += c2_es_a[c2_i46 + c2_i45] * c2_tu_b[c2_i47];
      c2_i46 += 3;
    }
  }

  for (c2_i48 = 0; c2_i48 < 3; c2_i48++) {
    c2_r0_c4[c2_i48] = c2_d4[c2_i48] + c2_dx_y[c2_i48];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
  for (c2_i49 = 0; c2_i49 < 9; c2_i49++) {
    c2_es_a[c2_i49] = c2_R5[c2_i49];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i50 = 0; c2_i50 < 3; c2_i50++) {
    c2_dx_y[c2_i50] = 0.0;
    c2_i51 = 0;
    for (c2_i52 = 0; c2_i52 < 3; c2_i52++) {
      c2_dx_y[c2_i50] += c2_es_a[c2_i51 + c2_i50] * c2_uu_b[c2_i52];
      c2_i51 += 3;
    }
  }

  for (c2_i53 = 0; c2_i53 < 3; c2_i53++) {
    c2_r0_c5[c2_i53] = c2_d5[c2_i53] + c2_dx_y[c2_i53];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
  for (c2_i54 = 0; c2_i54 < 9; c2_i54++) {
    c2_es_a[c2_i54] = c2_R6[c2_i54];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i55 = 0; c2_i55 < 3; c2_i55++) {
    c2_dx_y[c2_i55] = 0.0;
    c2_i56 = 0;
    for (c2_i57 = 0; c2_i57 < 3; c2_i57++) {
      c2_dx_y[c2_i55] += c2_es_a[c2_i56 + c2_i55] * c2_vu_b[c2_i57];
      c2_i56 += 3;
    }
  }

  for (c2_i58 = 0; c2_i58 < 3; c2_i58++) {
    c2_r0_c6[c2_i58] = c2_d6[c2_i58] + c2_dx_y[c2_i58];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i59 = 0; c2_i59 < 3; c2_i59++) {
    (*c2_b_r0_c1)[c2_i59] = c2_r0_c1[c2_i59];
  }

  for (c2_i60 = 0; c2_i60 < 3; c2_i60++) {
    (*c2_b_r0_c2)[c2_i60] = c2_r0_c2[c2_i60];
  }

  for (c2_i61 = 0; c2_i61 < 3; c2_i61++) {
    (*c2_b_r0_c3)[c2_i61] = c2_r0_c3[c2_i61];
  }

  for (c2_i62 = 0; c2_i62 < 3; c2_i62++) {
    (*c2_b_r0_c4)[c2_i62] = c2_r0_c4[c2_i62];
  }

  for (c2_i63 = 0; c2_i63 < 3; c2_i63++) {
    (*c2_b_r0_c5)[c2_i63] = c2_r0_c5[c2_i63];
  }

  for (c2_i64 = 0; c2_i64 < 3; c2_i64++) {
    (*c2_b_r0_c6)[c2_i64] = c2_r0_c6[c2_i64];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_JointSpaceControl_CorrectInertia
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i65;
  real_T c2_b_inData[3];
  int32_T c2_i66;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i65 = 0; c2_i65 < 3; c2_i65++) {
    c2_b_inData[c2_i65] = (*(real_T (*)[3])c2_inData)[c2_i65];
  }

  for (c2_i66 = 0; c2_i66 < 3; c2_i66++) {
    c2_u[c2_i66] = c2_b_inData[c2_i66];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_r0_c6, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_r0_c6), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_r0_c6);
}

static void c2_b_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv14[3];
  int32_T c2_i67;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv14, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i67 = 0; c2_i67 < 3; c2_i67++) {
    c2_y[c2_i67] = c2_dv14[c2_i67];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_r0_c6;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i68;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_r0_c6 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_r0_c6), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_r0_c6);
  for (c2_i68 = 0; c2_i68 < 3; c2_i68++) {
    (*(real_T (*)[3])c2_outData)[c2_i68] = c2_y[c2_i68];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i69;
  real_T c2_b_inData[6];
  int32_T c2_i70;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i69 = 0; c2_i69 < 6; c2_i69++) {
    c2_b_inData[c2_i69] = (*(real_T (*)[6])c2_inData)[c2_i69];
  }

  for (c2_i70 = 0; c2_i70 < 6; c2_i70++) {
    c2_u[c2_i70] = c2_b_inData[c2_i70];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  real_T c2_b_inData[9];
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i71 = 0;
  for (c2_i72 = 0; c2_i72 < 3; c2_i72++) {
    for (c2_i73 = 0; c2_i73 < 3; c2_i73++) {
      c2_b_inData[c2_i73 + c2_i71] = (*(real_T (*)[9])c2_inData)[c2_i73 + c2_i71];
    }

    c2_i71 += 3;
  }

  c2_i74 = 0;
  for (c2_i75 = 0; c2_i75 < 3; c2_i75++) {
    for (c2_i76 = 0; c2_i76 < 3; c2_i76++) {
      c2_u[c2_i76 + c2_i74] = c2_b_inData[c2_i76 + c2_i74];
    }

    c2_i74 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv15[9];
  int32_T c2_i77;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv15, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i77 = 0; c2_i77 < 9; c2_i77++) {
    c2_y[c2_i77] = c2_dv15[c2_i77];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_R6;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_R6 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_R6), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_R6);
  c2_i78 = 0;
  for (c2_i79 = 0; c2_i79 < 3; c2_i79++) {
    for (c2_i80 = 0; c2_i80 < 3; c2_i80++) {
      (*(real_T (*)[9])c2_outData)[c2_i80 + c2_i78] = c2_y[c2_i80 + c2_i78];
    }

    c2_i78 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i81;
  real_T c2_b_inData[3];
  int32_T c2_i82;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i81 = 0; c2_i81 < 3; c2_i81++) {
    c2_b_inData[c2_i81] = (*(real_T (*)[3])c2_inData)[c2_i81];
  }

  for (c2_i82 = 0; c2_i82 < 3; c2_i82++) {
    c2_u[c2_i82] = c2_b_inData[c2_i82];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray
  *sf_c2_JointSpaceControl_CorrectInertia_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[17];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i83;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17), FALSE);
  for (c2_i83 = 0; c2_i83 < 17; c2_i83++) {
    c2_r0 = &c2_info[c2_i83];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i83);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i83);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i83);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i83);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i83);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i83);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i83);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i83);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[17])
{
  c2_info[0].context = "";
  c2_info[0].name = "cos";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[0].fileTimeLo = 1343851972U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[1].name = "eml_scalar_cos";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[1].fileTimeLo = 1286840322U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "sin";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[2].fileTimeLo = 1343851986U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[3].name = "eml_scalar_sin";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[3].fileTimeLo = 1286840336U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "mtimes";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].fileTimeLo = 1289541292U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "mrdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].fileTimeLo = 1357973148U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 1319751566U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileTimeLo = 1346531988U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "eml_scalexp_compatible";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[7].fileTimeLo = 1286840396U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].name = "eml_div";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[8].fileTimeLo = 1313369410U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "eml_index_class";
  c2_info[9].dominantType = "";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[9].fileTimeLo = 1323192178U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "eml_scalar_eg";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[10].fileTimeLo = 1286840396U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "eml_xgemm";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[11].fileTimeLo = 1299098372U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[12].name = "eml_blas_inline";
  c2_info[12].dominantType = "";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[12].fileTimeLo = 1299098368U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[13].name = "mtimes";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].fileTimeLo = 1289541292U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[14].name = "eml_index_class";
  c2_info[14].dominantType = "";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[14].fileTimeLo = 1323192178U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[15].name = "eml_scalar_eg";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[15].fileTimeLo = 1286840396U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[16].name = "eml_refblas_xgemm";
  c2_info[16].dominantType = "char";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[16].fileTimeLo = 1299098374U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_JointSpaceControl_CorrectInertiaInstanceStruct
  *chartInstance)
{
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i84;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i84, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i84;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_JointSpaceControl_CorrectInertia, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_JointSpaceControl_CorrectInertia), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_JointSpaceControl_CorrectInertia);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_JointSpaceControl_CorrectInertia_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2647993180U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1439668053U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3799914969U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(287260595U);
}

mxArray *sf_c2_JointSpaceControl_CorrectInertia_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AHIBPiDULbfGazNp2VjmfF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_JointSpaceControl_CorrectInertia_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_JointSpaceControl_CorrectInertia
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"r0_c1\",},{M[1],M[11],T\"r0_c2\",},{M[1],M[12],T\"r0_c3\",},{M[1],M[13],T\"r0_c4\",},{M[1],M[14],T\"r0_c5\",},{M[1],M[15],T\"r0_c6\",},{M[8],M[0],T\"is_active_c2_JointSpaceControl_CorrectInertia\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_JointSpaceControl_CorrectInertia_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
    chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _JointSpaceControl_CorrectInertiaMachineNumber_,
           2,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_JointSpaceControl_CorrectInertiaMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _JointSpaceControl_CorrectInertiaMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _JointSpaceControl_CorrectInertiaMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,2,0,1,"r0_c1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"r0_c2");
          _SFD_SET_DATA_PROPS(3,2,0,1,"r0_c3");
          _SFD_SET_DATA_PROPS(4,2,0,1,"r0_c4");
          _SFD_SET_DATA_PROPS(5,2,0,1,"r0_c5");
          _SFD_SET_DATA_PROPS(6,2,0,1,"r0_c6");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,11857);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T (*c2_q)[6];
          real_T (*c2_r0_c1)[3];
          real_T (*c2_r0_c2)[3];
          real_T (*c2_r0_c3)[3];
          real_T (*c2_r0_c4)[3];
          real_T (*c2_r0_c5)[3];
          real_T (*c2_r0_c6)[3];
          c2_r0_c6 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 6);
          c2_r0_c5 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 5);
          c2_r0_c4 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 4);
          c2_r0_c3 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_r0_c2 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c2_r0_c1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_q = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_q);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_r0_c1);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_r0_c2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_r0_c3);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_r0_c4);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_r0_c5);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_r0_c6);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _JointSpaceControl_CorrectInertiaMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "bP9o76gL5mFY7TkgzYkN3";
}

static void sf_opaque_initialize_c2_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
  initialize_c2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  enable_c2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  disable_c2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  sf_c2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c2_JointSpaceControl_CorrectInertia(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_JointSpaceControl_CorrectInertia
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_JointSpaceControl_CorrectInertia
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_JointSpaceControl_CorrectInertia
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c2_JointSpaceControl_CorrectInertia(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_JointSpaceControl_CorrectInertia(S);
}

static void sf_opaque_set_sim_state_c2_JointSpaceControl_CorrectInertia
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_JointSpaceControl_CorrectInertia(S, st);
}

static void sf_opaque_terminate_c2_JointSpaceControl_CorrectInertia(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_JointSpaceControl_CorrectInertia_optimization_info();
    }

    finalize_c2_JointSpaceControl_CorrectInertia
      ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_JointSpaceControl_CorrectInertia
    ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_JointSpaceControl_CorrectInertia(SimStruct
  *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_JointSpaceControl_CorrectInertia
      ((SFc2_JointSpaceControl_CorrectInertiaInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_JointSpaceControl_CorrectInertia_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(196087453U));
  ssSetChecksum1(S,(218430813U));
  ssSetChecksum2(S,(1965044933U));
  ssSetChecksum3(S,(3970439684U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_JointSpaceControl_CorrectInertia(SimStruct *S)
{
  SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *chartInstance;
  chartInstance = (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct *)
    utMalloc(sizeof(SFc2_JointSpaceControl_CorrectInertiaInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_JointSpaceControl_CorrectInertiaInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_JointSpaceControl_CorrectInertia;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_JointSpaceControl_CorrectInertia_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_JointSpaceControl_CorrectInertia(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_JointSpaceControl_CorrectInertia(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_JointSpaceControl_CorrectInertia(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_JointSpaceControl_CorrectInertia_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
