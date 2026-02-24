#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/loader/Keybinds.hpp>
using namespace geode::prelude;
using namespace keybinds;

$execute {
  BindManager::get()->registerBindable({
    "enter-search"_spr,
    "Enter Search",
    "Search when you press enter in the level search page",
    { Keybind::create(KEY_Enter, Modifier::None) },
    Category::GLOBAL
  });
}

class $modify(LevelSearchLayer) {
  bool init(int p0) {
    if (!LevelSearchLayer::init(p0)) {
      return false;
    }
    this->template addEventListener<InvokeBindFilter>([this](InvokeBindEvent* event) {
      auto levelSearch = CCDirector::get()->getRunningScene()->getChildByID("LevelSearchLayer");
      if (event->isDown() && levelSearch != nullptr) {
        this->onSearch(nullptr);
      }
      return ListenerResult::Propagate;
    }, "enter-search"_spr);
    return true;
  }
};

