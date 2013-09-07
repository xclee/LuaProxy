
#ifndef __LUAScrollVIEW__
#define __LUAScrollVIEW__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif
//#include "GUI/CCScrollView/CCScrollView.h"
#include "CCLuaEngine.h"
#include "ExtensionMacros.h"
#include "cocos2d.h"
#include "LuaEventHandler.h"



USING_NS_CC;

class LuaScrollView:public cocos2d::extension::CCScrollView,public cocos2d::extension::CCScrollViewDelegate
{
public:
    static LuaScrollView *create(LuaEventHandler *h); //
    virtual ~LuaScrollView();
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual bool ccTouchBegan(CCTouch *t, CCEvent *e);
    
    void registerScriptScrollViewHandler(int handler);
    void unregisterScriptScrollViewHandler(void);
    
    void handleScriptEventHandler(const char *str);
    void registerWithTouchDispatcher();
protected:
    int m_nScriptHandler;
    LuaEventHandler *_handler;
};

TOLUA_API int tolua_LuaScrollView_open(lua_State* tolua_S);
#endif
