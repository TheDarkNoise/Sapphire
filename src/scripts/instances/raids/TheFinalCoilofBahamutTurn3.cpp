#include <ScriptObject.h>
#include <Territory/InstanceContent.h>

using namespace Sapphire;

class TheFinalCoilofBahamutTurn3 : public Sapphire::ScriptAPI::InstanceContentScript
{
public:
  TheFinalCoilofBahamutTurn3() : Sapphire::ScriptAPI::InstanceContentScript( 30018 )
  { }

  void onInit( InstanceContent& instance ) override
  {
    instance.addEObj( "unknown_0", 2004611, 0, 4985093, 4, { -7.491028f, -53.235149f, -153.215500f }, 1.000000f, 0.000000f, 0); 
    instance.addEObj( "unknown_1", 2004610, 0, 4995707, 4, { 22.322800f, -53.235241f, -154.775101f }, 1.000000f, 0.000000f, 0); 
    instance.addEObj( "sgvf_w1b3_b0502", 2004627, 5009741, 5009742, 4, { 0.000000f, -53.682961f, -160.000000f }, 1.000000f, 0.000000f, 0); 
    // States -> brr_off (id: 2) brr_on2off (id: 3) brr_on (id: 4) brr_off2on (id: 5) 
    instance.addEObj( "unknown_2", 2004638, 0, 5012220, 4, { -14.415940f, -53.682961f, -162.090302f }, 1.000000f, 0.000000f, 0); 
    instance.addEObj( "Entrance", 2000182, 4895872, 4895873, 5, { 0.005331f, -53.234989f, -140.846207f }, 1.000000f, 0.000000f, 0); 
    // States -> vf_lock_on (id: 11) vf_lock_of (id: 12) 
    instance.addEObj( "Entrypoint", 2004650, 0, 4895874, 4, { -0.019161f, -53.626511f, -182.364700f }, 1.000000f, 0.000000f, 0); 

  }

  void onUpdate( InstanceContent& instance, uint64_t tickCount ) override
  {

  }

  void onEnterTerritory( InstanceContent& instance, Entity::Player& player, uint32_t eventId, uint16_t param1,
                         uint16_t param2 ) override
  {

  }

};

EXPOSE_SCRIPT( TheFinalCoilofBahamutTurn3 );