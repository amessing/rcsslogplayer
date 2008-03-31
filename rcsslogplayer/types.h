// -*-c++-*-

/*!
  \file types.h
  \brief Type definitions for rcg data format.
*/

/*
 *Copyright:

 Copyright (C) The RoboCup Soccer Server Maintenance Group.
               Hidehisa AKIYAMA

 This code is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 *EndCopyright:
 */

/////////////////////////////////////////////////////////////////////

#ifndef RCSSLOGPLAYER_TYPES_H
#define RCSSLOGPLAYER_TYPES_H

#include <boost/cstdint.hpp>

#include <string>

namespace rcss {
namespace rcg {

typedef boost::int16_t Int16;
typedef boost::uint16_t UInt16;
typedef boost::int32_t Int32;
typedef boost::int32_t UInt32;

/*!
  \enum PlayerState
  \brief player state bit mask.
 */
enum PlayerState {
    DISABLE = 0x00000000,
    STAND = 0x00000001,
    KICK = 0x00000002,
    KICK_FAULT = 0x00000004,
    GOALIE = 0x00000008,
    CATCH = 0x00000010,
    CATCH_FAULT = 0x00000020,
    BALL_TO_PLAYER = 0x00000040,
    PLAYER_TO_BALL = 0x00000080,
    DISCARD = 0x00000100,
    LOST = 0x00000200, // [I.Noda:00/05/13] added for 3D viewer/commentator/small league
    BALL_COLLIDE = 0x00000400, // player collided with the ball
    PLAYER_COLLIDE = 0x00000800, // player collided with another player
    TACKLE = 0x00001000,
    TACKLE_FAULT = 0x00002000,
    BACK_PASS = 0x00004000,
    FREE_KICK_FAULT = 0x00008000,
    POST_COLLIDE = 0x00010000, // player collided with goal posts
};

/*!
  \enum Side
  \brief side type definition
*/
enum Side {
    LEFT = 1,
    NEUTRAL = 0,
    RIGHT = -1
};

//! playmode string table defined in rcssserver.
#define PLAYMODE_STRINGS {"",                   \
            "before_kick_off",                  \
            "time_over",                        \
            "play_on",                          \
            "kick_off_l",                       \
            "kick_off_r",                       \
            "kick_in_l",                        \
            "kick_in_r",                        \
            "free_kick_l",                      \
            "free_kick_r",                      \
            "corner_kick_l",                    \
            "corner_kick_r",                    \
            "goal_kick_l",                      \
            "goal_kick_r",                      \
            "goal_l",                           \
            "goal_r",                           \
            "drop_ball",                        \
            "offside_l",                        \
            "offside_r",                        \
            "penalty_kick_l",                   \
            "penalty_kick_r",                   \
            "first_half_over",                  \
            "pause",                            \
            "human_judge",                      \
            "foul_charge_l",                    \
            "foul_charge_r",                    \
            "foul_push_l",                      \
            "foul_push_r",                      \
            "foul_multiple_attack_l",           \
            "foul_multiple_attack_r",           \
            "foul_ballout_l",                   \
            "foul_ballout_r",                   \
            "back_pass_l",                      \
            "back_pass_r",                      \
            "free_kick_fault_l",                \
            "free_kick_fault_r",                \
            "catch_fault_l",                    \
            "catch_fault_r",                    \
            "indirect_free_kick_l",             \
            "indirect_free_kick_r",             \
            "penalty_setup_l",                  \
            "penalty_setup_r",                  \
            "penalty_ready_l",                  \
            "penalty_ready_r",                  \
            "penalty_taken_l",                  \
            "penalty_taken_r",                  \
            "penalty_miss_l",                   \
            "penalty_miss_r",                   \
            "penalty_score_l",                  \
            "penalty_score_r"                   \
            }

/*!
  \enum PlayMode
  \brief playmode types defined in rcssserver/src/types.h
 */
enum PlayMode {
    PM_Null,
    PM_BeforeKickOff,
    PM_TimeOver,
    PM_PlayOn,
    PM_KickOff_Left,
    PM_KickOff_Right,
    PM_KickIn_Left,
    PM_KickIn_Right,
    PM_FreeKick_Left,
    PM_FreeKick_Right,
    PM_CornerKick_Left,
    PM_CornerKick_Right,
    PM_GoalKick_Left,
    PM_GoalKick_Right,
    PM_AfterGoal_Left,
    PM_AfterGoal_Right,
    PM_Drop_Ball,
    PM_OffSide_Left,
    PM_OffSide_Right,
    // [I.Noda:00/05/13] added for 3D viewer/commentator/small league
    PM_PK_Left,
    PM_PK_Right,
    PM_FirstHalfOver,
    PM_Pause,
    PM_Human,
    PM_Foul_Charge_Left,
    PM_Foul_Charge_Right,
    PM_Foul_Push_Left,
    PM_Foul_Push_Right,
    PM_Foul_MultipleAttacker_Left,
    PM_Foul_MultipleAttacker_Right,
    PM_Foul_BallOut_Left,
    PM_Foul_BallOut_Right,
    PM_Back_Pass_Left,
    PM_Back_Pass_Right,
    PM_Free_Kick_Fault_Left,
    PM_Free_Kick_Fault_Right,
    PM_CatchFault_Left,
    PM_CatchFault_Right,
    PM_IndFreeKick_Left,
    PM_IndFreeKick_Right,
    PM_PenaltySetup_Left,
    PM_PenaltySetup_Right,
    PM_PenaltyReady_Left,
    PM_PenaltyReady_Right,
    PM_PenaltyTaken_Left,
    PM_PenaltyTaken_Right,
    PM_PenaltyMiss_Left,
    PM_PenaltyMiss_Right,
    PM_PenaltyScore_Left,
    PM_PenaltyScore_Right,
    PM_MAX
};

//! max number of players for one team
const int MAX_PLAYER = 11;

const double SHOWINFO_SCALE = 16.0;
const float SHOWINFO_SCALEF = 16.0f;
const double SHOWINFO_SCALE2 = 65536.0;
const float SHOWINFO_SCALE2F = 65536.0f;

const int REC_OLD_VERSION = 1;
const int REC_VERSION_2 = 2;
const int REC_VERSION_3 = 3;
const int REC_VERSION_4 = 4;
const int DEFAULT_REC_VERSION = REC_VERSION_4;

/*!
  \enum DispInfoMode
  \brief monitor data types. */
enum DispInfoMode {
    NO_INFO = 0,
    SHOW_MODE = 1,
    MSG_MODE = 2,
    DRAW_MODE = 3,
    BLANK_MODE = 4,
    PM_MODE = 5,
    TEAM_MODE = 6,
    PT_MODE = 7,
    PARAM_MODE = 8,
    PPARAM_MODE = 9,
};

/*!
  \enum MsgInfoMode
  \brief message data type id enumeration
 */
enum MsgInfoMode {
    MSG_BOARD = 1,
    LOG_BOARD = 2
};

/*!
  \struct pos_t
  \brief movable object data for old log format
*/
struct pos_t {
    Int16 enable;
    Int16 side;
    Int16 unum;
    Int16 angle;
    Int16 x;
    Int16 y;
};

/*!
  \struct team_t
  \brief team data for old log format
*/
struct team_t {
    char name[16];
    Int16 score;
};

/*!
  \struct showinfo_t
  \brief view data for rcg v1
*/
struct showinfo_t {
    char pmode;
    team_t team[2];
    pos_t pos[MAX_PLAYER * 2 + 1];
    Int16 time;
};

//! max message length in msginfo_t
const int max_message_length_for_display = 2048;

/*!
  \struct msginfo_t
  \brief message data for binary format log
*/
struct msginfo_t {
    Int16 board;
    char message[max_message_length_for_display];
};

//! max length of color name string
const int COLOR_NAME_MAX = 64;

/*!
  \struct pointinfo_t
  \brief point data in drawinfo_t
*/
struct pointinfo_t {
    Int16 x;
    Int16 y;
    char color[COLOR_NAME_MAX];
};

/*!
  \struct circleinfo_t
  \brief circle data in drawinfo_t
*/
struct circleinfo_t {
    Int16 x;
    Int16 y;
    Int16 r;
    char color[COLOR_NAME_MAX];
};

/*!
  \struct lineinfo_t
  \brief line data in drawinfo_t
*/
struct lineinfo_t {
    Int16 x1;
    Int16 y1;
    Int16 x2;
    Int16 y2;
    char color[COLOR_NAME_MAX];
};

/*!
  \struct drawinfo_t
  \brief drawing data for binary format log
*/
struct drawinfo_t {
    Int16 mode;
    union {
        pointinfo_t		pinfo;
        circleinfo_t	cinfo;
        lineinfo_t		linfo;
    } object;
};

/*!
  \struct dispinfo_t
  \brief display data for old montor protocol
 */
struct dispinfo_t {
    Int16 mode;
    union {
        showinfo_t	show;
        msginfo_t	msg;
        drawinfo_t	draw;
    } body;
};

/*!
  \struct ball_t
  \brief ball data for rcg v3
*/
struct ball_t {
    Int32 x;
    Int32 y;
    Int32 deltax;
    Int32 deltay;
};

/*!
  \struct player_t
  \brief player data for rcg v3
*/
struct player_t {
    Int16 mode;
    Int16 type;
    Int32 x;
    Int32 y;
    Int32 deltax;
    Int32 deltay;
    Int32 body_angle;
    Int32 head_angle;
    Int32 view_width;
    Int16 view_quality;
    Int32 stamina;
    Int32 effort;
    Int32 recovery;
    Int16 kick_count;
    Int16 dash_count;
    Int16 turn_count;
    Int16 say_count;
    Int16 turn_neck_count;
    Int16 catch_count;
    Int16 move_count;
    Int16 change_view_count;
};

/*!
  \struct showinfo_t2
  \brief view data for monitor protocol v2
*/
struct showinfo_t2 {
    char pmode;
    team_t team[2];
    ball_t ball;
    player_t pos[MAX_PLAYER * 2];
    Int16 time;
};

/*!
  \struct short_showinfo_t2
  \brief view data for rcg v3
*/
struct short_showinfo_t2 {
    ball_t ball;
    player_t pos[MAX_PLAYER * 2];
    Int16 time;
};

/*!
  \struct player_type_t
  \brief player type parameters for rcg v3
 */
struct player_type_t {
    Int16 id; //!< type id
    Int32 player_speed_max; //!< max speed
    Int32 stamina_inc_max; //!< max stamina increment value
    Int32 player_decay; //!< speed decay
    Int32 inertia_moment; //!< inertia moment
    Int32 dash_power_rate; //!< dash power rate
    Int32 player_size; //!< body radius
    Int32 kickable_margin; //!< kickable margin
    Int32 kick_rand; //!< random factor for kick
    Int32 extra_stamina; //!< extra stamina value when stamina is 0.
    Int32 effort_max; //!< max(initial) effort value
    Int32 effort_min; //!< min effort value

    Int32 sparelong1; //!< spare variable
    Int32 sparelong2; //!< spare variable
    Int32 sparelong3; //!< spare variable
    Int32 sparelong4; //!< spare variable
    Int32 sparelong5; //!< spare variable
    Int32 sparelong6; //!< spare variable
    Int32 sparelong7; //!< spare variable
    Int32 sparelong8; //!< spare variable
    Int32 sparelong9; //!< spare variable
    Int32 sparelong10; //!< spare variable
};

/*!
  \struct player_params_t
  \brief heterogenious player trade-off parametors for rcg v3
*/
struct player_params_t {
    Int16 player_types; //!< the number of player types
    Int16 substitute_max; //!< max player substitution
    Int16 pt_max; //!< max each player type on field
    Int32 player_speed_max_delta_min; //!< minimal value wighin delta range
    Int32 player_speed_max_delta_max; //!< maximal value wighin delta range
    Int32 stamina_inc_max_delta_factor; //!< tradeoff parameter
    Int32 player_decay_delta_min; //!< minimal value wighin delta range
    Int32 player_decay_delta_max; //!< maximal value wighin delta range
    Int32 inertia_moment_delta_factor; //!< tradeoff parameter
    Int32 dash_power_rate_delta_min; //!< minimal value wighin delta range
    Int32 dash_power_rate_delta_max; //!< maximal value wighin delta range
    Int32 player_size_delta_factor; //!< tradeoff parameter
    Int32 kickable_margin_delta_min; //!< minimal value wighin delta range
    Int32 kickable_margin_delta_max; //!< maximal value wighin delta range
    Int32 kick_rand_delta_factor; //!< tradeoff parameter
    Int32 extra_stamina_delta_min; //!< minimal value wighin delta range
    Int32 extra_stamina_delta_max; //!< maximal value wighin delta range
    Int32 effort_max_delta_factor; //!< tradeoff parameter
    Int32 effort_min_delta_factor; //!< tradeoff parameter
    Int32 random_seed; //!< random seed to generate parameters
    Int32 new_dash_power_rate_delta_min; //!< minimal value wighin delta range
    Int32 new_dash_power_rate_delta_max; //!< maximal value wighin delta range
    Int32 new_stamina_inc_max_delta_factor; //!< tradeoff parameter

    Int32 sparelong5; //!< spare variable
    Int32 sparelong6; //!< spare variable
    Int32 sparelong7; //!< spare variable
    Int32 sparelong8; //!< spare variable
    Int32 sparelong9; //!< spare variable
    Int32 sparelong10; //!< spare variable

    Int16 allow_mult_default_type; //!< whether multiple default type is allowed

    Int16 spareshort2; //!< spare variable
    Int16 spareshort3; //!< spare variable
    Int16 spareshort4; //!< spare variable
    Int16 spareshort5; //!< spare variable
    Int16 spareshort6; //!< spare variable
    Int16 spareshort7; //!< spare variable
    Int16 spareshort8; //!< spare variable
    Int16 spareshort9; //!< spare variable
    Int16 spareshort10; //!< spare variable
};

/*!
  \struct server_params_t
  \brief server parametors for rcg v3
 */
struct server_params_t {
    Int32 goal_width; //!< goal width
    Int32 inertia_moment; //!< related to player's turn action
    Int32 player_size; //!< normal player size
    Int32 player_decay; //!< normal player speed decay
    Int32 player_rand; //!< noize added to normal player movement
    Int32 player_weight; //!< normal player weight
    Int32 player_speed_max; //!< normal player speed max
    Int32 player_accel_max; //!< normal player accel max
    Int32 stamina_max; //!< normal player stamina max
    Int32 stamina_inc; //!< normal player stamina inc
    Int32 recover_init; //!< normal player recovery init
    Int32 recover_dec_thr; //!< normal player recovery decriment threshold
    Int32 recover_min; //!< normal player recovery min
    Int32 recover_dec; //!< normal player recovery decriment
    Int32 effort_init; //!< normal player dash effort init
    Int32 effort_dec_thr; //!< normal player dash effort decriment threshold
    Int32 effort_min; //!< normal player dash effrot min
    Int32 effort_dec; //!< normal player dash effort decriment
    Int32 effort_inc_thr; //!< normal player dash effort incriment threshold
    Int32 effort_inc; //!< normal player dash effort incriment
    Int32 kick_rand;  //!< noise added directly to normal player's kick
    Int16 team_actuator_noise; //!< flag whether to use team specific actuator noise
    Int32 player_rand_factor_l; //!< factor to multiple prand for left team
    Int32 player_rand_factor_r; //!< factor to multiple prand for right team
    Int32 kick_rand_factor_l; //!< factor to multiple kick_rand for left team
    Int32 kick_rand_factor_r; //!< factor to multiple kick_rand for right team
    Int32 ball_size; //!< ball size
    Int32 ball_decay; //!< ball speed decay
    Int32 ball_rand; //!< noise added to ball movement
    Int32 ball_weight; //!< ball weight
    Int32 ball_speed_max; //!< ball speed max
    Int32 ball_accel_max; //!< ball acceleration max
    Int32 dash_power_rate; //!< normal player's dash power rate
    Int32 kick_power_rate; //!< normal player's kick power rate
    Int32 kickable_margin; //!< normal player's kickable margin
    Int32 control_radius; //!< control radius
    Int32 control_radius_width; //!< (control radius) - (plyaer size)
    Int32 max_power; //!< max power
    Int32 min_power; //!< min power
    Int32 max_moment; //!< max moment
    Int32 min_moment; //!< min moment
    Int32 max_neck_moment; //!< max neck moment
    Int32 min_neck_moment; //!< min neck moment
    Int32 max_neck_angle; //!< max neck angle
    Int32 min_neck_angle; //!< min neck angle
    Int32 visible_angle; //!< visible angle
    Int32 visible_distance; //!< visible distance
    Int32 wind_dir; //!< wind direction
    Int32 wind_force; //!< wind force
    Int32 wind_angle; //!< wind angle for rand
    Int32 wind_rand; //!< wind noise for force
    Int32 kickable_area; //!< kickable_area
    Int32 catchable_area_l; //!< goalie catchable area length
    Int32 catchable_area_w; //!< goalie catchable area width
    Int32 catch_probability; //!< goalie catchable possibility
    Int16 goalie_max_moves; //!< goalie max moves after a catch
    Int32 corner_kick_margin; //!< corner kick margin
    Int32 offside_active_area_size; //!< offside active area size
    Int16 wind_none; //!< wind factor is none
    Int16 wind_random; //!< wind factor is random
    Int16 say_coach_count_max; //!< max count of coach's freeform say message
    Int16 say_coach_msg_size; //!< max length of coach's freeform say message
    Int16 clang_win_size; //!< window of coach language window
    Int16 clang_define_win; //!< window of coach language define message
    Int16 clang_meta_win; //!< window of coach lauguage meta message
    Int16 clang_advice_win; //!< window of coach language advice message
    Int16 clang_info_win; //!< window of coach language info message
    Int16 clang_mess_delay; //!< coach language advise message is delayed this cycle
    Int16 clang_mess_per_cycle; //!< online coach can send CLang advise per this cycle
    Int16 half_time; //!<  half time cycle
    Int16 simulator_step; //!< simulator step interval msec
    Int16 send_step; //!< udp send step interval msec
    Int16 recv_step; //!< udp recv step interval msec
    Int16 sense_body_step; //!< sense_body interval step msec
    Int16 lcm_step; //!< lcm of all the above steps msec
    Int16 say_msg_size; //!< string size of say message
    Int16 hear_max; //!< player hear_capacity_max
    Int16 hear_inc; //!< player hear_capacity_inc
    Int16 hear_decay; //!< player hear_capacity_decay
    Int16 catch_ban_cycle; //!< goalie catch ban cycle
    Int16 slow_down_factor; //!< factor to slow down simulator and send intervals
    Int16 use_offside; //!< flag for using off side rule
    Int16 forbid_kick_off_offside; //!< flag for permit kick off offside
    Int32 offside_kick_margin; //!< offside kick margin
    Int32 audio_cut_dist; //!< audio cut off distance
    Int32 quantize_step; //!< quantize step of distance
    Int32 landmark_quantize_step; //!< quantize step of distance for landmark
    Int32 dir_quantize_step; //!< quantize step of direction
    Int32 dist_quantize_step_l; //!< team right quantize step of distance
    Int32 dist_quantize_step_r; //!< team left quantize step of distance
    Int32 landmark_dist_quantize_step_l; //!< team right quantize step of distance for landmark
    Int32 landmark_dist_quantize_step_r; //!< team left quantize step of distance for landmark
    Int32 dir_quantize_step_l; //!< team left quantize step of direction
    Int32 dir_quantize_step_r; //!< team right quantize step of direction
    Int16 coach_mode; //!< coach mode
    Int16 coach_with_referee_mode; //!< coach with referee mode
    Int16 old_coach_hear; //!< old format for hear command (coach)
    Int16 send_vi_step; //!< online coach's look interval step
    Int32 slowness_on_top_for_left_team;  //!< flag for left team dash power rate reduction on field top area
    Int32 slowness_on_top_for_right_team; //!< flag for right team dash power rate reduction on field top area

    Int32 keepaway_length; //!< keep away region length
    Int32 keepaway_width;  //!< keep away region width

    Int32 ball_stuck_area; //!< automatic drop ball threshold while play_on

    Int32 max_tackle_power; //!< allowed maximum tackle power
    Int32 max_back_tackle_power; //!< allowed minimum tackle power

    Int32 tackle_dist; //!< forward tackle area length
    Int32 tackle_back_dist; //!< back tackle area length
    Int32 tackle_width; //!< tackle area width

    Int16 start_goal_l; //!< initial left team score
    Int16 start_goal_r; //!< initial right team score
    Int16 fullstate_l; //!< flag for left team's fullstate info receive
    Int16 fullstate_r; //!< flag for right team's fullstate info receive
    Int16 drop_ball_time; //!< automatically drop_ball waiting cycle
    Int16 synch_mode; //!< flag for using synchronized mode
    Int16 synch_offset; //!< wheh sync_mode, server decide the message sent to clients before this number[ms]
    Int16 synch_micro_sleep; //!< the number of microseconds to sleep while waiting for players */
    Int16 point_to_ban; //!< player continue to point to the same point at least during this cycle
    Int16 point_to_duration; //!< point_to command has effectiveness during this cycle
};

/*!
  \struct dispinfo_t2
  \brief display data for monitor protocol v2
*/
struct dispinfo_t2 {
    Int16 mode;
    union {
        showinfo_t2 		show;
        msginfo_t 		msg;
        player_type_t		ptinfo;
        server_params_t		sparams;
        player_params_t		pparams;
    } body;
};

//
// Data structures for the text based monitor protocl
//

/*!
  \struct BallT
  \brief generic ball data for display information
 */
struct BallT {
    float x_; //!< ball position x
    float y_; //!< ball position y
    float vx_; //!< ball velocity x
    float vy_; //!< ball velocity y

    /*!
      \brief initialize all variables by 0
     */
    BallT()
        : x_( 0.0 )
        , y_( 0.0 )
        , vx_( 0.0 )
        , vy_( 0.0 )
      { }
};

/*!
  \struct PlayerT
  \brief generic player data for display information
 */
struct PlayerT {
    char side_; //!< player's side. 'l', 'r' or 'n'
    Int16 unum_; //!< player's uniform number. 0 means disabled player.
    Int16 type_; //!< heterogeneous player type id

    char view_quality_; //!< view quality indicator, 'l' or 'h'

    char focus_side_; //!< focus target side. 'l', 'r' or 'n'. 'n' means no focus target.
    Int16 focus_unum_; //!< focus target uniform number. 0 means no focus target.

    Int32 state_; //!< state bit flags

    float x_; //!< position x
    float y_; //!< position y
    float vx_; //!< velocity x
    float vy_; //!< velocity y
    float body_; //!< body direction (degree)
    float neck_; //!< head direction relative to body (degree)
    float point_x_; //!< arm pointing x
    float point_y_; //!< arm pointing y

    float view_width_; //!< view width (degree). high: value>0, low: value<0

    float stamina_; //!< satamina value
    float effort_; //!< effort value
    float recovery_; //!< recovery value

    UInt16 kick_count_; //!< kick command count
    UInt16 dash_count_; //!< dash command count
    UInt16 turn_count_; //!< turn command count
    UInt16 catch_count_; //!< catch command count
    UInt16 move_count_; //!< move command count
    UInt16 turn_neck_count_; //!< turn_neck command count
    UInt16 change_view_count_; //!< change_view command count
    UInt16 say_count_; //!< say command count
    UInt16 tackle_count_; //!< tackle command count
    UInt16 pointto_count_; //!< pointto command count
    UInt16 attentionto_count_; //!< attentionto command count

    /*!
      \brief initialize all variables
     */
    PlayerT()
        : side_( 'n' )
        , unum_( 0 )
        , type_( -1 )
        , view_quality_( 'h' )
        , focus_side_( 'n' )
        , focus_unum_( 0 )
        , state_( 0 )
        , x_( 0.0f )
        , y_( 0.0f )
        , vx_( 0.0f )
        , vy_( 0.0f )
        , body_( 0.0f )
        , neck_( 0.0f )
        , point_x_( SHOWINFO_SCALE2F )
        , point_y_( SHOWINFO_SCALE2F )
        , view_width_( 0.0f )
        , stamina_( -1.0f )
        , effort_( 0.0f )
        , recovery_( 0.0f )
        , kick_count_( 0 )
        , dash_count_( 0 )
        , turn_count_( 0 )
        , catch_count_( 0 )
        , move_count_( 0 )
        , turn_neck_count_( 0 )
        , change_view_count_( 0 )
        , say_count_( 0 )
        , tackle_count_( 0 )
        , pointto_count_( 0 )
        , attentionto_count_( 0 )
      { }

    /*!
      \brief get side id
      \return side id
     */
    Side side() const
      {
          return ( side_ == 'l' ? LEFT
                   : side_ == 'r' ? RIGHT
                   : NEUTRAL );
      }

    bool highQuality() const
      {
          return ( view_quality_ == 'h' );
      }

    /*!
      \brief get focused player's side id
      \return side id
     */
    Side focusSide() const
      {
          return ( side_ == 'l' ? LEFT
                   : side_ == 'r' ? RIGHT
                   : NEUTRAL );
      }
};

/*!
  \struct TeamT
  \brief team information
 */
struct TeamT {
    std::string name_; //!< team name string
    UInt16 score_; //!< total scores in normal game
    UInt16 pen_score_; //!< count of penalty score
    UInt16 pen_miss_; //!< count of penalty miss

    /*!
      \brief initialize all variables by 0
     */
    TeamT()
        : score_( 0 )
        , pen_score_( 0 )
        , pen_miss_( 0 )
      { }

    /*!
      \brief initialize all variables by specified values
      \param name team name
      \param score total score
      \param pen_score count of penalty score
      \param pen_miss count of penalty miss
     */
    TeamT( const char * name,
           const UInt16 score,
           const UInt16 pen_score,
           const UInt16 pen_miss )
        : name_( name )
        , score_( score )
        , pen_score_( pen_score )
        , pen_miss_( pen_miss )
      { }

    /*!
      \brief clear all variables
     */
    void clear()
      {
          name_.erase();
          score_ = 0;
          pen_score_ = 0;
          pen_miss_ = 0;
      }

    /*!
      \brief get the total penalty trial count
      \return the total penalty trial count
     */
    int penaltyTrial() const
      {
          return pen_score_ + pen_miss_;
      }

    /*!
      \brief check if artument variable has same values.
      \param other compared variable.
      \return compared result.
     */
    bool equals( const TeamT & other ) const
      {
          return ( name_ == other.name_
                   && score_ == other.score_
                   && pen_score_ == other.pen_score_
                   && pen_miss_ == other.pen_miss_ );
      }

};

/*!
  \struct ShowInfoT
  \brief show information
 */
struct ShowInfoT {
    UInt32 time_;
    BallT ball_;
    PlayerT player_[MAX_PLAYER * 2];
};


/*!
  \struct DispInfoT
  \brief display information
 */
struct DispInfoT {
    PlayMode pmode_;
    TeamT team_[2];
    ShowInfoT show_;
};

/*!
  \struct ServerTypeT
  \brief player type parameters
 */
struct PlayerTypeT {
    int id_;
    double player_speed_max_;
    double stamina_inc_max_;
    double player_decay_;
    double inertia_moment_;
    double dash_power_rate_;
    double player_size_;
    double kickable_margin_;
    double kick_rand_;
    double extra_stamina_;
    double effort_max_;
    double effort_min_;

    PlayerTypeT()
        : id_( 0 )
        , player_speed_max_( 1.2 )
        , stamina_inc_max_( 45.0 )
        , player_decay_( 0.4 )
        , inertia_moment_( 5.0 )
        , dash_power_rate_( 0.06 )
        , player_size_( 0.3 )
        , kickable_margin_( 0.7 )
        , kick_rand_( 0.1 )
        , extra_stamina_( 0.0 )
        , effort_max_( 1.0 )
        , effort_min_( 0.6 )
      { }
};

/*!
  \struct PlayerParamT
  \brief heterogenious player trade-off parameters
 */
struct PlayerParamT {
    int player_types_;
    int subs_max_;
    int pt_max_;

    bool allow_mult_default_type_;

    double player_speed_max_delta_min_;
    double player_speed_max_delta_max_;
    double stamina_inc_max_delta_factor_;

    double player_decay_delta_min_;
    double player_decay_delta_max_;
    double inertia_moment_delta_factor_;

    double dash_power_rate_delta_min_;
    double dash_power_rate_delta_max_;
    double player_size_delta_factor_;

    double kickable_margin_delta_min_;
    double kickable_margin_delta_max_;
    double kick_rand_delta_factor_;

    double extra_stamina_delta_min_;
    double extra_stamina_delta_max_;
    double effort_max_delta_factor_;
    double effort_min_delta_factor_;

    double new_dash_power_rate_delta_min_;
    double new_dash_power_rate_delta_max_;
    double new_stamina_inc_max_delta_factor_;

    int random_seed_;

    PlayerParamT()
        : player_types_( 18 )
        , subs_max_( 3 )
        , pt_max_( 1 )
        , allow_mult_default_type_( false )
        , player_speed_max_delta_min_( 0.0 )
        , player_speed_max_delta_max_( 0.0 )
        , stamina_inc_max_delta_factor_( 0.0 )
        , player_decay_delta_min_( -0.05 )
        , player_decay_delta_max_( 0.1 )
        , inertia_moment_delta_factor_( 25.0 )
        , dash_power_rate_delta_min_( 0.0 )
        , dash_power_rate_delta_max_( 0.0 )
        , player_size_delta_factor_( -100.0 )
        , kickable_margin_delta_min_( -0.1 )
        , kickable_margin_delta_max_( 0.1 )
        , kick_rand_delta_factor_( 1.0 )
        , extra_stamina_delta_min_( 0.0 )
        , extra_stamina_delta_max_( 100.0 )
        , effort_max_delta_factor_( -0.002 )
        , effort_min_delta_factor_( -0.002 )
        , new_dash_power_rate_delta_min_( -0.0005 )
        , new_dash_power_rate_delta_max_( 0.0015 )
        , new_stamina_inc_max_delta_factor_( -6000.0 )
        , random_seed_( -1 )
      { }
};

/*!
  \struct ServerParamT
  \brief server parameters
 */
struct ServerParamT {
    double goal_width_;
    double inertia_moment_;
    double player_size_;
    double player_decay_;
    double player_rand_;
    double player_weight_;
    double player_speed_max_;
    double player_accel_max_;
    double stamina_max_;
    double stamina_inc_max_;
    double recover_init_;
    double recover_dec_thr_;
    double recover_min_;
    double recover_dec_;
    double effort_init_;
    double effort_dec_thr_;
    double effort_min_;
    double effort_dec_;
    double effort_inc_thr_;
    double effort_inc_;
    double kick_rand_;
    bool team_actuator_noise_;
    double player_rand_factor_l_;
    double player_rand_factor_r_;
    double kick_rand_factor_l_;
    double kick_rand_factor_r_;
    double ball_size_;
    double ball_decay_;
    double ball_rand_;
    double ball_weight_;
    double ball_speed_max_;
    double ball_accel_max_;
    double dash_power_rate_;
    double kick_power_rate_;
    double kickable_margin_;
    double control_radius_;
    double control_radius_width_;
    double catch_probability_;
    double catchable_area_l_;
    double catchable_area_w_;
    int goalie_max_moves_;
    double max_power_;
    double min_power_;
    double max_moment_;
    double min_moment_;
    double max_neck_moment_;
    double min_neck_moment_;
    double max_neck_angle_;
    double min_neck_angle_;
    double visible_angle_;
    double visible_distance_;
    double audio_cut_dist_;
    double quantize_step_;
    double landmark_quantize_step_;
    double corner_kick_margin_;
    double wind_dir_;
    double wind_force_;
    double wind_angle_;
    double wind_rand_;
    bool wind_none_;
    bool wind_random_;
    int half_time_;
    int drop_ball_time_;
    int port_;
    int coach_port_;
    int online_coach_port_;
    int say_coach_count_max_;
    int say_coach_msg_size_;
    int simulator_step_;
    int send_step_; // player's see message interval for (normal,high) mode
    int recv_step_;
    int sense_body_step_;
    int say_msg_size_;
    int clang_win_size_;
    int clang_define_win_;
    int clang_meta_win_;
    int clang_advice_win_;
    int clang_info_win_;
    int clang_del_win_;
    int clang_rule_win_;
    int clang_mess_delay_;
    int clang_mess_per_cycle_;
    int hear_max_;
    int hear_inc_;
    int hear_decay_;
    int catch_ban_cycle_;
    bool coach_mode_;
    bool coach_with_referee_mode_;
    bool old_coach_hear_;
    int send_vi_step_; // online coach's see_global interval
    bool use_offside_;
    double offside_active_area_size_;
    bool forbid_kick_off_offside_;
    bool verbose_;
    double offside_kick_margin_;
    int slow_down_factor_;
    bool synch_mode_;
    int synch_offset_;
    int synch_micro_sleep_;
    int start_goal_l_;
    int start_goal_r_;
    bool fullstate_l_;
    bool fullstate_r_;
    double slowness_on_top_for_left_team_;
    double slowness_on_top_for_right_team_;
    std::string landmark_file_;
    bool send_comms_;
    bool text_logging_;
    bool game_logging_;
    int game_log_version_;
    std::string text_log_dir_;
    std::string game_log_dir_;
    std::string text_log_fixed_name_;
    std::string game_log_fixed_name_;
    bool text_log_fixed_;
    bool game_log_fixed_;
    bool text_log_dated_;
    bool game_log_dated_;
    std::string log_date_format_;
    bool log_times_;
    bool record_messages_;
    int text_log_compression_;
    int game_log_compression_;
    bool profile_;
    int point_to_ban_;
    int point_to_duration_;
    double tackle_dist_;
    double tackle_back_dist_;
    double tackle_width_;
    double tackle_exponent_;
    int tackle_cycles_;
    double tackle_power_rate_;
    int freeform_wait_period_;
    int freeform_send_period_;
    bool free_kick_faults_;
    bool back_passes_;
    bool proper_goal_kicks_;
    double stopped_ball_vel_;
    int max_goal_kicks_;
    bool auto_mode_;
    int kick_off_wait_;
    int connect_wait_;
    int game_over_wait_;
    std::string team_l_start_;
    std::string team_r_start_;
    bool keepaway_mode_;
    double keepaway_length_;
    double keepaway_width_;
    bool keepaway_logging_;
    std::string keepaway_log_dir_;
    std::string keepaway_log_fixed_name_;
    bool keepaway_log_fixed_;
    bool keepaway_log_dated_;
    int keepaway_start_;
    int nr_normal_halfs_;
    int nr_extra_halfs_;
    bool penalty_shoot_outs_;
    int pen_before_setup_wait_;
    int pen_setup_wait_;
    int pen_ready_wait_;
    int pen_taken_wait_;
    int pen_nr_kicks_;
    int pen_max_extra_kicks_;
    double pen_dist_x_;
    bool pen_random_winner_;
    double pen_max_goalie_dist_x_;
    bool pen_allow_mult_kicks_;
    bool pen_coach_moves_players_;
    double ball_stuck_area_;
    std::string coach_msg_file_;
    double max_tackle_power_;
    double max_back_tackle_power_;
    double player_speed_max_min_;
    double extra_stamina_;

    int synch_see_offset_;
    int max_monitors_;

    double reliable_catch_area_l_;
    double min_catch_probability_;

    ServerParamT()
        :goal_width_( 14.02 )
        ,inertia_moment_( 5.0 )
        , player_size_( 0.3 )
        , player_decay_( 0.4 )
        , player_rand_( 0.1 )
        , player_weight_( 60.0 )
        , player_speed_max_( 1.2 )
        , player_accel_max_( 1.0 )
        , stamina_max_( 4000.0 )
        , stamina_inc_max_( 45.0 )
        , recover_init_( 1.0 )
        , recover_dec_thr_( 0.3 )
        , recover_min_( 0.5 )
        , recover_dec_( 0.002 )
        , effort_init_( 1.0 )
        , effort_dec_thr_( 0.3 )
        , effort_min_( 0.6 )
        , effort_dec_( 0.005 )
        , effort_inc_thr_( 0.6 )
        , effort_inc_( 0.01 )
        , kick_rand_( 0.1 )
        , team_actuator_noise_( false )
        , player_rand_factor_l_( 1.0 )
        , player_rand_factor_r_( 1.0 )
        , kick_rand_factor_l_( 1.0 )
        , kick_rand_factor_r_( 1.0 )
        , ball_size_( 0.085 )
        , ball_decay_( 0.94 )
        , ball_rand_( 0.05 )
        , ball_weight_( 0.2 )
        , ball_speed_max_( 3.0 )
        , ball_accel_max_( 2.7 )
        , dash_power_rate_( 0.006 )
        , kick_power_rate_( 0.027 )
        , kickable_margin_( 0.7 )
        , control_radius_( 2.0 )
        , control_radius_width_( 1.7 )
        , catch_probability_( 1.0 )
        , catchable_area_l_( 1.2 )
        , catchable_area_w_( 1.0 )
        , goalie_max_moves_( 2 )
        , max_power_( 100.0 )
        , min_power_( -100.0 )
        , max_moment_( 180.0 )
        , min_moment_( -180.0 )
        , max_neck_moment_( 180.0 )
        , min_neck_moment_( -180.0 )
        , max_neck_angle_( 90.0 )
        , min_neck_angle_( -90.0 )
        , visible_angle_( 90.0 )
        , visible_distance_( 3.0 )
        , audio_cut_dist_( 50.0 )
        , quantize_step_( 0.1 )
        , landmark_quantize_step_( 0.01 )
        , corner_kick_margin_( 1.0 )
        , wind_dir_( 0.0 )
        , wind_force_( 0.0 )
        , wind_angle_( 0.0 )
        , wind_rand_( 0.0 )
        , wind_none_( false )
        , wind_random_( false )
        , half_time_( 300 )
        , drop_ball_time_( 200 )
        , port_( 6000 )
        , coach_port_( 6001 )
        , online_coach_port_( 6002 )
        , say_coach_count_max_( 128 )
        , say_coach_msg_size_( 128 )
        , simulator_step_( 100 )
        , send_step_( 150 )
        , recv_step_( 10 )
        , sense_body_step_( 100 )
        , say_msg_size_( 10 )
        , clang_win_size_( 300 )
        , clang_define_win_( 1 )
        , clang_meta_win_( 1 )
        , clang_advice_win_( 1 )
        , clang_info_win_( 1 )
        , clang_del_win_( 1 )
        , clang_rule_win_( 1 )
        , clang_mess_delay_( 50 )
        , clang_mess_per_cycle_( 1 )
        , hear_max_( 1 )
        , hear_inc_( 1 )
        , hear_decay_( 1 )
        , catch_ban_cycle_( 5 )
        , coach_mode_( false )
        , coach_with_referee_mode_( false )
        , old_coach_hear_( false )
        , send_vi_step_( 100 )
        , use_offside_( true )
        , offside_active_area_size_( 2.5 )
        , forbid_kick_off_offside_( true )
        , verbose_( false )
        , offside_kick_margin_( 9.15 )
        , slow_down_factor_( 1 )
        , synch_mode_( false )
        , synch_offset_( 60 )
        , synch_micro_sleep_( 1 )
        , start_goal_l_( 0 )
        , start_goal_r_( 0 )
        , fullstate_l_( false )
        , fullstate_r_( false )
        , slowness_on_top_for_left_team_( 1.0 )
        , slowness_on_top_for_right_team_( 1.0 )
        , landmark_file_()
        , send_comms_( false )
        , text_logging_( true )
        , game_logging_( true )
        , game_log_version_( 4 )
        , text_log_dir_( "." )
        , game_log_dir_( "." )
        , text_log_fixed_name_( "rcssserver" )
        , game_log_fixed_name_( "rcssserver" )
        , text_log_fixed_( false )
        , game_log_fixed_( false )
        , text_log_dated_( true )
        , game_log_dated_( true )
        , log_date_format_( "%Y%m%d%H%M-" )
        , log_times_( false )
        , record_messages_( false )
        , text_log_compression_( 0 )
        , game_log_compression_( 0 )
        , profile_( false )
        , point_to_ban_( 5 )
        , point_to_duration_( 20 )
        , tackle_dist_( 2.0 )
        , tackle_back_dist_( 0.5 )
        , tackle_width_( 1.0 )
        , tackle_exponent_( 6.0 )
        , tackle_cycles_( 10 )
        , tackle_power_rate_( 0.027 )
        , freeform_wait_period_( 600 )
        , freeform_send_period_( 20 )
        , free_kick_faults_( true )
        , back_passes_( true )
        , proper_goal_kicks_( false )
        , stopped_ball_vel_( 0.01 )
        , max_goal_kicks_( 3 )
        , auto_mode_( false )
        , kick_off_wait_( 100 )
        , connect_wait_( 300 )
        , game_over_wait_( 100 )
        , team_l_start_()
        , team_r_start_()
        , keepaway_mode_( false )
        , keepaway_length_( 20.0 )
        , keepaway_width_( 20.0 )
        , keepaway_logging_( true )
        , keepaway_log_dir_( "." )
        , keepaway_log_fixed_name_( "rcssserver" )
        , keepaway_log_fixed_( false )
        , keepaway_log_dated_( true )
        , keepaway_start_( -1 )
        , nr_normal_halfs_( 2 )
        , nr_extra_halfs_( 2 )
        , penalty_shoot_outs_( true )
        , pen_before_setup_wait_( 30 )
        , pen_setup_wait_( 100 )
        , pen_ready_wait_( 50 )
        , pen_taken_wait_( 200 )
        , pen_nr_kicks_( 5 )
        , pen_max_extra_kicks_( 10 )
        , pen_dist_x_( 42.5 )
        , pen_random_winner_( false )
        , pen_max_goalie_dist_x_( 14.0 )
        , pen_allow_mult_kicks_( true )
        , pen_coach_moves_players_( true )
        , ball_stuck_area_( 3.0 )
        , coach_msg_file_()
        , max_tackle_power_( 100.0 )
        , max_back_tackle_power_( 50.0 )
        , player_speed_max_min_( 0.8 )
        , extra_stamina_( 0.0 )
        , synch_see_offset_( 30 )
        , max_monitors_( -1 )
        , reliable_catch_area_l_( 1.2 )
        , min_catch_probability_( 1.0 )
      { }
};


}
}

#endif
