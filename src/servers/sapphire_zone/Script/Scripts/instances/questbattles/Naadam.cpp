#include <ScriptObject.h>
#include <Zone/InstanceContent.h>

class Naadam : public InstanceContentScript
{
public:
   Naadam() : InstanceContentScript( 5008 )
   { }

   void onInit( InstanceContentPtr instance ) override
   {

   }

   void onUpdate( InstanceContentPtr instance, uint32_t currTime ) override
   {

   }

   void onEnterTerritory( Entity::Player &player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
   {

   }

};