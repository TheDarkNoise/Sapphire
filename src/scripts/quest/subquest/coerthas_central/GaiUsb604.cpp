// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include "Manager/EventMgr.h"
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>

#include "Actor/BNpc.h"
#include "Manager/TerritoryMgr.h"
#include "Territory/Territory.h"

// Quest Script: GaiUsb604_00886
// Quest Name: The Unending War
// Quest ID: 66422
// Start NPC: 1006372
// End NPC: 1006377

using namespace Sapphire;

class GaiUsb604 : public Sapphire::ScriptAPI::QuestScript
{
private:
  // Basic quest information
  // Quest vars / flags used
  // BitFlag8
  // UI8AL

  /// Countable Num: 0 Seq: 1 Event: 10 Listener: 5000000
  /// Countable Num: 0 Seq: 2 Event: 1 Listener: 1006731
  /// Countable Num: 0 Seq: 3 Event: 5 Listener: 724
  /// Countable Num: 0 Seq: 255 Event: 5 Listener: 725
  // Steps in this quest ( 0 is before accepting,
  // 1 is first, 255 means ready for turning it in
  enum Sequence : uint8_t
  {
    Seq0 = 0,
    Seq1 = 1,
    Seq2 = 2,
    Seq3 = 3,
    SeqFinish = 255,
  };

  // Entities found in the script data of the quest
  static constexpr auto Actor0 = 1006372;//Ludovoix
  static constexpr auto Actor1 = 1006731;//Keeled-over Knight
  static constexpr auto Actor2 = 1006376;//Edmelle
  static constexpr auto Actor3 = 1006377;//Forlemort
  static constexpr auto Enemy0 = 4289901;
  static constexpr auto Enemy1 = 4289905;
  static constexpr auto Eobject0 = 2002503;
  static constexpr auto Eventrange0 = 4289908;
  static constexpr auto EventActionRescueUnderMiddle = 35;
  static constexpr auto EventActionSearch = 1;
  static constexpr auto LocActor0 = 1006902;

public:
  GaiUsb604() : Sapphire::ScriptAPI::QuestScript( 66422 ){};
  ~GaiUsb604() = default;

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( World::Quest& quest, Entity::Player& player, uint64_t actorId ) override
  {
    switch( actorId )
    {
      case Actor0:
      {
        if( quest.getSeq() == Seq0 )
          Scene00000( quest, player );
        else if( quest.getSeq() == Seq2 )
          Scene00007( quest, player );
        break;
      }
      case Actor1:
      {
        if( quest.getSeq() == Seq1 )
        {
          if( quest.getUI8AL() < 2 )
            Scene00003( quest, player );
          else
            eventMgr().eventActionStart(
                    player, getId(), EventActionRescueUnderMiddle,
                    [ & ]( Entity::Player& player, uint32_t eventId, uint64_t additional ) {
                      Scene00004( quest, player );
                    },
                    nullptr, 0 );
        }
        break;
      }
      case Actor2:
      {
        if( quest.getSeq() == Seq3 )
          Scene00008( quest, player );
        break;
      }
      case Actor3:
      {
        if( quest.getSeq() == SeqFinish )
          Scene00009( quest, player );
        break;
      }
    }
  }

  void onBNpcKill( World::Quest& quest, uint16_t nameId, uint32_t entityId, Entity::Player& player ) override
  {
    switch( entityId )
    {
      case Enemy0:
      case Enemy1:
      {
        quest.setUI8AL( quest.getUI8AL() + 1 );
        break;
      }
    }
  }

  void onWithinRange( World::Quest& quest, Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    if( param1 == Eventrange0 )
    {
      auto instance = teriMgr().getTerritoryByGuId( player.getTerritoryId() );

      auto enemy0Spawned = instance->getActiveBNpcByInstanceIdAndTriggerOwner( Enemy0, player.getId() );
      auto enemy1Spawned = instance->getActiveBNpcByInstanceIdAndTriggerOwner( Enemy1, player.getId() );

      if( !enemy0Spawned && !enemy1Spawned && quest.getUI8AL() < 2 )
        Scene00002( quest, player );
    }
  }

private:
  //////////////////////////////////////////////////////////////////////
  // Available Scenes in this quest, not necessarly all are used
  //////////////////////////////////////////////////////////////////////

  void Scene00000( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 0, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00000Return ) );
  }

  void Scene00000Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    if( result.getResult( 0 ) == 1 )// accept quest
    {
      Scene00001( quest, player );
    }
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00001( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 1, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00001Return ) );
  }

  void Scene00001Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    quest.setSeq( Seq1 );
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00002( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 2, NONE /*Yes*/, bindSceneReturn( &GaiUsb604::Scene00002Return ) );
  }

  void Scene00002Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    auto instance = teriMgr().getTerritoryByGuId( player.getTerritoryId() );

    auto enemy0 = instance->createBNpcFromInstanceId( Enemy0, 1220 /*Find the right value*/, Common::BNpcType::Enemy, player.getId() );
    auto enemy1 = instance->createBNpcFromInstanceId( Enemy1, 1220 /*Find the right value*/, Common::BNpcType::Enemy, player.getId() );

    enemy0->hateListAdd( player.getAsPlayer(), 1 );
    enemy1->hateListAdd( player.getAsPlayer(), 1 );
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00003( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 3, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00003Return ) );
  }

  void Scene00003Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00004( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 4, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00004Return ) );
  }

  void Scene00004Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    eventMgr().sendEventNotice( player, getId(), 0, 0 );
    quest.setSeq( Seq2 );
    quest.setUI8AL( 0 );
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00005( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 5, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00005Return ) );
  }

  void Scene00005Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00006( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 6, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00006Return ) );
  }

  void Scene00006Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00007( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 7, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00007Return ) );
  }

  void Scene00007Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    eventMgr().sendEventNotice( player, getId(), 1, 0 );
    quest.setSeq( Seq3 );
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00008( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 8, HIDE_HOTBAR, bindSceneReturn( &GaiUsb604::Scene00008Return ) );
  }

  void Scene00008Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {
    eventMgr().sendEventNotice( player, getId(), 2, 0 );
    quest.setSeq( SeqFinish );
  }

  //////////////////////////////////////////////////////////////////////

  void Scene00009( World::Quest& quest, Entity::Player& player )
  {
    eventMgr().playQuestScene( player, getId(), 9, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, bindSceneReturn( &GaiUsb604::Scene00009Return ) );
  }

  void Scene00009Return( World::Quest& quest, Entity::Player& player, const Event::SceneResult& result )
  {

    if( result.getResult( 0 ) == 1 )
    {
      player.finishQuest( getId() );
    }
  }
};

EXPOSE_SCRIPT( GaiUsb604 );