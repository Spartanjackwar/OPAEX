//================================================================================
//Aerodynamics
maxSpeed = 666; //Last successful version was 550.  This affects thrust!
maxFordingDepth = 0.8; //Float on water? hydrodynamics is aerodynamics right? Don't quote that.
vtol = 4; //0=none. 1=VTOL. 2=STOVL. 3=VTOL: ground vector limit. 4=VTOL, nozzles start at 90.
VTOLYawInfluence = 4;
VTOLPitchInfluence = 2;
VTOLRollInfluence = 2;
//angleOfIndicence = "1*3.1415/180"; //Taken from the Y-32 Xi'an, or VTOL_02_BASE_F
envelope[] = {0, 0.01, 0.2, 4, 6, 7.6, 8.4, 9.2, 9.4, 9.6, 9.7, 9.8, 8, 1};

//Aerodynamics: Ailerons
aileronSensitivity = 0.9;
aileronControlsSensitivityCoef = 0.8;
aileronCoef[] = {0.6, 0.8, 1, 1.1, 1.2, 1.15, 0.1};

//Aerodynamics: Elevators
elevatorSensitivity = 0.9;
elevatorControlsSensitivityCoef = 0.8;
elevatorCoef[] = {0.33, 0.39, 0.51, 0.6, 0.68, 0.75, 0.8, 0.85, 0.9, 0.74, 0.3};

//Aerodynamics: Rudders
rudderInfluence = 0.01; //this is the cosine of the angle the rudder moves for some ungodly reason.
rudderControlsSensitivityCoef = 1;
//rudderCoef[] = {0.5, 0.7, 1, 1.8, 2.1, 2.25, 2.5, 2.6, 2.66, 2.7, 2.7, 0.8, 0.4};
rudderCoef[] = {0.5, 0.7, 1, 1.8, 2.1, 2.25, 2.33, 2, 1.7, 1, 0.9, 0.82, 0.77};

//Aerodynamics: Flaps, airbrakes, and hook
flaps = 0;
airbrake = 1;
airBrakeFrictionCoef = 5;
tailhook = 0;

//Aerodynamics: Drag forces profile
draconicForceXCoef = 6.6;
draconicForceYCoef = 1.5;
draconicForceZCoef = 0.22;
draconicTorqueXCoef[] = {3.5, 3, 2.8, 2.65, 2.475, 2.4, 2.425, 2.625, 2.75, 2.875, 3};
draconicTorqueYCoef[] = {0, 0.5, 1.2, 2, 3, 2.6, 2.4, 2.2, 2, 1.9, 1.8};

//Aerodynamics: Airflow drag profile
airFrictionCoefs2[] = {0.001, 0.005, 6.4e-005};
airFrictionCoefs1[] = {0.1, 0.0469, 0.012}; //0% -33% 0% reductions.
airFrictionCoefs0[] = {0.0, 0.0, 0.0};

//Aerodynamics: Thrust
thrustCoef[] = {2, 1.96, 1.89, 1.76, 1.71, 1.69, 1.66, 1.50, 1.30, 1, 0.9, 0.82, 0.33, 0, 0, 0};
altFullForce = 2000; //Above this altitude begins the decrease in thrust performance
altNoForce = 7000; //Above this altitude thrust is useless.