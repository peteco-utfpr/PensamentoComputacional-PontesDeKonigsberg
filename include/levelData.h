#define ISLAND_SOUTH_POSITION   {700, 850}
#define ISLAND_CENTER_POSITION  {800, 350}
#define ISLAND_NORTH_POSITION   {1250, 32}
#define ISLAND_EAST_POSITION    {1600, 540}

enum Island{
    north,
    east,
    south,
    center,
    total
};

#define BACKGROUND_TEXTURE "./assets/fundo.png"
#define EULER_TEXTURE "./assets/euler.png"
#define BRIDGE_TEXTURE "./assets/ponte.png"
#define WHITE_FLAG_TEXTURE "./assets/flag.png"
#define BUTTON_FONT_PATH "./assets/anirm__.ttf"
#define CROSSING_SOUND_PATH "./assets/steps.ogg"

#define GIVE_UP_BUTTON_POSITION {100, 900}
#define WHITE_FLAG_POSITION     {10, 900}
#define WHITE_FLAG_SCALE        {0.1, 0.1}


// IMPOSSIBLE LEVEL DATA ---------------------------------------------------------------

//bridge data, all the parameters of every bridge in the level
#define IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES   7

#define IMPOSSIBLE_LEVEL_BRIDGE1_POSITION    {1220.0, 470.0}
#define IMPOSSIBLE_LEVEL_BRIDGE1_SCALE       {7.0, 7.0} 
#define IMPOSSIBLE_LEVEL_BRIDGE1_ROTATION    0
#define IMPOSSIBLE_LEVEL_BRIDGE1_SOURCE      Island::east
#define IMPOSSIBLE_LEVEL_BRIDGE1_DEST        Island::center

#define IMPOSSIBLE_LEVEL_BRIDGE2_POSITION    {1250.0, 900.0}
#define IMPOSSIBLE_LEVEL_BRIDGE2_SCALE       {7.0,7.0}
#define IMPOSSIBLE_LEVEL_BRIDGE2_ROTATION    -10
#define IMPOSSIBLE_LEVEL_BRIDGE2_SOURCE      Island::east
#define IMPOSSIBLE_LEVEL_BRIDGE2_DEST        Island::south

#define IMPOSSIBLE_LEVEL_BRIDGE3_POSITION    {1000.0, 660.0}
#define IMPOSSIBLE_LEVEL_BRIDGE3_SCALE       {7.0,7.0}
#define IMPOSSIBLE_LEVEL_BRIDGE3_ROTATION    90
#define IMPOSSIBLE_LEVEL_BRIDGE3_SOURCE      Island::south
#define IMPOSSIBLE_LEVEL_BRIDGE3_DEST        Island::center

#define IMPOSSIBLE_LEVEL_BRIDGE4_POSITION    {710.0, 610.0}
#define IMPOSSIBLE_LEVEL_BRIDGE4_SCALE       {7.0,7.0}
#define IMPOSSIBLE_LEVEL_BRIDGE4_ROTATION    98
#define IMPOSSIBLE_LEVEL_BRIDGE4_SOURCE      Island::south
#define IMPOSSIBLE_LEVEL_BRIDGE4_DEST        Island::center

#define IMPOSSIBLE_LEVEL_BRIDGE5_POSITION    {820.0, 260.0}
#define IMPOSSIBLE_LEVEL_BRIDGE5_SCALE       {7.0,7.0}
#define IMPOSSIBLE_LEVEL_BRIDGE5_ROTATION    285
#define IMPOSSIBLE_LEVEL_BRIDGE5_SOURCE      Island::north
#define IMPOSSIBLE_LEVEL_BRIDGE5_DEST        Island::center

#define IMPOSSIBLE_LEVEL_BRIDGE6_POSITION    {1070.0, 300.0}
#define IMPOSSIBLE_LEVEL_BRIDGE6_SCALE       {7.0,7.0}
#define IMPOSSIBLE_LEVEL_BRIDGE6_ROTATION    285
#define IMPOSSIBLE_LEVEL_BRIDGE6_SOURCE      Island::north
#define IMPOSSIBLE_LEVEL_BRIDGE6_DEST        Island::center

#define IMPOSSIBLE_LEVEL_BRIDGE7_POSITION    {1550.0, 130.0}
#define IMPOSSIBLE_LEVEL_BRIDGE7_SCALE       {7.0,7.0}
#define IMPOSSIBLE_LEVEL_BRIDGE7_ROTATION    85
#define IMPOSSIBLE_LEVEL_BRIDGE7_SOURCE      Island::east
#define IMPOSSIBLE_LEVEL_BRIDGE7_DEST        Island::north

//vectors over which we'll iterate when loading the level
#define IMPOSSIBLE_LEVEL_BRIDGE_POSITION_VECTOR {                  \
                                IMPOSSIBLE_LEVEL_BRIDGE1_POSITION, \
                                IMPOSSIBLE_LEVEL_BRIDGE2_POSITION, \
                                IMPOSSIBLE_LEVEL_BRIDGE3_POSITION, \
                                IMPOSSIBLE_LEVEL_BRIDGE4_POSITION, \
                                IMPOSSIBLE_LEVEL_BRIDGE5_POSITION, \
                                IMPOSSIBLE_LEVEL_BRIDGE6_POSITION, \
                                IMPOSSIBLE_LEVEL_BRIDGE7_POSITION, \
                               }

#define IMPOSSIBLE_LEVEL_BRIDGE_SCALE_VECTOR {               \
                             IMPOSSIBLE_LEVEL_BRIDGE1_SCALE, \
                             IMPOSSIBLE_LEVEL_BRIDGE2_SCALE, \
                             IMPOSSIBLE_LEVEL_BRIDGE3_SCALE, \
                             IMPOSSIBLE_LEVEL_BRIDGE4_SCALE, \
                             IMPOSSIBLE_LEVEL_BRIDGE5_SCALE, \
                             IMPOSSIBLE_LEVEL_BRIDGE6_SCALE, \
                             IMPOSSIBLE_LEVEL_BRIDGE7_SCALE, \
                            }

#define IMPOSSIBLE_LEVEL_BRIDGE_ROTATION_VECTOR {                  \
                                IMPOSSIBLE_LEVEL_BRIDGE1_ROTATION, \
                                IMPOSSIBLE_LEVEL_BRIDGE2_ROTATION, \
                                IMPOSSIBLE_LEVEL_BRIDGE3_ROTATION, \
                                IMPOSSIBLE_LEVEL_BRIDGE4_ROTATION, \
                                IMPOSSIBLE_LEVEL_BRIDGE5_ROTATION, \
                                IMPOSSIBLE_LEVEL_BRIDGE6_ROTATION, \
                                IMPOSSIBLE_LEVEL_BRIDGE7_ROTATION, \
                               }

#define IMPOSSIBLE_LEVEL_BRIDGE_SOURCE_VECTOR {                  \
                                IMPOSSIBLE_LEVEL_BRIDGE1_SOURCE, \
                                IMPOSSIBLE_LEVEL_BRIDGE2_SOURCE, \
                                IMPOSSIBLE_LEVEL_BRIDGE3_SOURCE, \
                                IMPOSSIBLE_LEVEL_BRIDGE4_SOURCE, \
                                IMPOSSIBLE_LEVEL_BRIDGE5_SOURCE, \
                                IMPOSSIBLE_LEVEL_BRIDGE6_SOURCE, \
                                IMPOSSIBLE_LEVEL_BRIDGE7_SOURCE, \
                               }

#define IMPOSSIBLE_LEVEL_BRIDGE_DEST_VECTOR {                  \
                                IMPOSSIBLE_LEVEL_BRIDGE1_DEST, \
                                IMPOSSIBLE_LEVEL_BRIDGE2_DEST, \
                                IMPOSSIBLE_LEVEL_BRIDGE3_DEST, \
                                IMPOSSIBLE_LEVEL_BRIDGE4_DEST, \
                                IMPOSSIBLE_LEVEL_BRIDGE5_DEST, \
                                IMPOSSIBLE_LEVEL_BRIDGE6_DEST, \
                                IMPOSSIBLE_LEVEL_BRIDGE7_DEST, \
                               }

//----------------------------------------------------------------------------------------------


//POSSIBLE LEVEL
    //TODO
