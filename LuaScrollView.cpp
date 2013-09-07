/*
** Lua binding: LuaScrollView
** Generated automatically by tolua++-1.0.92 on Thu Aug 15 18:44:46 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "tolua_fix.h"
#ifdef __cplusplus
}
#endif

#include <map>
#include <string>
#include "LuaScrollView.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCLuaStack.h"
#include "CCLuaValue.h"
#include "CCLuaEngine.h"

using namespace cocos2d;
using namespace cocos2d::extension;


LuaScrollView *LuaScrollView::create(LuaEventHandler *h){ //
    LuaScrollView* pRet = new LuaScrollView();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    
    CC_SAFE_RETAIN(h);
	pRet->_handler = h;
    return pRet;
    
}
LuaScrollView::~LuaScrollView(){
    
    CC_SAFE_RELEASE(_handler);
}
void LuaScrollView::scrollViewDidScroll(CCScrollView* view){
    
    CCLog("LuaScrollView::scrollViewDidScroll %lf\n" , view->getContentOffset().x);
    _handler->scrollViewDidScroll(view);
    
}
void LuaScrollView::scrollViewDidZoom(CCScrollView* view){
    
    
}
void LuaScrollView::registerScriptScrollViewHandler(int handler){
    unregisterScriptScrollViewHandler();
    m_nScriptHandler = handler;
    this->setDelegate(this);
}
void LuaScrollView::unregisterScriptScrollViewHandler(void){
    
    if(0 != m_nScriptHandler )
    {
        CCScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(m_nScriptHandler);
        m_nScriptHandler = 0;
    }
    this->setDelegate(NULL);
}
void LuaScrollView::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, false);
}
void LuaScrollView::handleScriptEventHandler(const char *str){
    if (NULL != str && 0 != m_nScriptHandler)
    {
        //cocos2d::CCScriptEngineProtocol* pEngine = cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine();
        //TO.DO after 2.1.4 use CCScriptEngineProtocol
        CCLuaStack* stack = CCLuaEngine::defaultEngine()->getLuaStack();
        stack->clean();
        stack->pushString(str);
        
        stack->executeFunctionByHandler(m_nScriptHandler, 1);
    }
}

void LuaScrollView::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
	if(!isVisible()){
		return;
	}
    _handler->tableCellTouchEnded((CCTableView *)(this) , NULL , pTouch);
   
//	CCTableViewCell *cell = cellForTouch(pTouch);
//	if(cell){
//		LuaEventHandler *h = dynamic_cast<LuaEventHandler *>(m_pTableViewDelegate);
//		if(m_pTouches->count() == 1 && !isTouchMoved()){
//			if(h){	h->tableCellTouched(this, cell, pTouch);}
//			else{	m_pTableViewDelegate->tableCellTouched(this, cell);}
//		}else if(h){
//			h->tableCellTouchEnded(this, cell, pTouch);
//		}
//	}else{
//		printf("LTV.touchEnded cell is null %f,%f\n", pTouch->getLocation().x, pTouch->getLocation().y);
//	}
	CCScrollView::ccTouchEnded(pTouch, pEvent);
    //CCScrollView::deaccelerateScrolling
    //this->unschedule(schedule_selector(CCScrollView::deaccelerateScrolling));
    //if (_pageEnabled)
    
    CCScrollView::unscheduleAllSelectors();
    
}
bool LuaScrollView::ccTouchBegan(CCTouch *t, CCEvent *e){
	bool r = CCScrollView::ccTouchBegan(t, e);
//	if(r){
//		CCTableViewCell *c = cellForTouch(t);
//		LuaEventHandler *h = dynamic_cast<LuaEventHandler *>(m_pTableViewDelegate);
//		if(c && h){
//			h->tableCellTouchBegan(this, c, t);
//		}
//	}
	return r;
}





/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LuaScrollView (lua_State* tolua_S)
{
    LuaScrollView* self = (LuaScrollView*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LuaScrollView");
    tolua_usertype(tolua_S,"CCScrollViewDelegate");
    tolua_usertype(tolua_S,"CCEvent");
    tolua_usertype(tolua_S,"CCScrollView");
    tolua_usertype(tolua_S,"LuaEventHandler");
    tolua_usertype(tolua_S,"CCTouch");
}

/* method: create of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_create00
static int tolua_LuaScrollView_LuaScrollView_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"LuaEventHandler",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaEventHandler* h = ((LuaEventHandler*)  tolua_tousertype(tolua_S,2,0));
        {
            LuaScrollView* tolua_ret = (LuaScrollView*)  LuaScrollView::create(h);
            tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaScrollView");
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_delete00
static int tolua_LuaScrollView_LuaScrollView_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
        Mtolua_delete(self);
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scrollViewDidScroll of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_scrollViewDidScroll00
static int tolua_LuaScrollView_LuaScrollView_scrollViewDidScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"CCScrollView",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
        CCScrollView* view = ((CCScrollView*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scrollViewDidScroll'", NULL);
#endif
        {
            self->scrollViewDidScroll(view);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'scrollViewDidScroll'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scrollViewDidZoom of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_scrollViewDidZoom00
static int tolua_LuaScrollView_LuaScrollView_scrollViewDidZoom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"CCScrollView",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
        CCScrollView* view = ((CCScrollView*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scrollViewDidZoom'", NULL);
#endif
        {
            self->scrollViewDidZoom(view);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'scrollViewDidZoom'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchEnded of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_ccTouchEnded00
static int tolua_LuaScrollView_LuaScrollView_ccTouchEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
        CCTouch* pTouch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
        CCEvent* pEvent = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchEnded'", NULL);
#endif
        {
            self->ccTouchEnded(pTouch,pEvent);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'ccTouchEnded'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchBegan of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_ccTouchBegan00
static int tolua_LuaScrollView_LuaScrollView_ccTouchBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
        !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,4,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
        CCTouch* t = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
        CCEvent* e = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchBegan'", NULL);
#endif
        {
            bool tolua_ret = (bool)  self->ccTouchBegan(t,e);
            tolua_pushboolean(tolua_S,(bool)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'ccTouchBegan'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerScriptScrollViewHandler of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_registerScriptScrollViewHandler00
static int tolua_LuaScrollView_LuaScrollView_registerScriptScrollViewHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
        int handler = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerScriptScrollViewHandler'", NULL);
#endif
        {
            self->registerScriptScrollViewHandler(handler);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'registerScriptScrollViewHandler'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterScriptScrollViewHandler of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_unregisterScriptScrollViewHandler00
static int tolua_LuaScrollView_LuaScrollView_unregisterScriptScrollViewHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterScriptScrollViewHandler'", NULL);
#endif
        {
            self->unregisterScriptScrollViewHandler();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'unregisterScriptScrollViewHandler'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleScriptEventHandler of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_handleScriptEventHandler00
static int tolua_LuaScrollView_LuaScrollView_handleScriptEventHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
        const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleScriptEventHandler'", NULL);
#endif
        {
            self->handleScriptEventHandler(str);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'handleScriptEventHandler'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerWithTouchDispatcher of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_LuaScrollView_LuaScrollView_registerWithTouchDispatcher00
static int tolua_LuaScrollView_LuaScrollView_registerWithTouchDispatcher00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"LuaScrollView",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerWithTouchDispatcher'", NULL);
#endif
        {
            self->registerWithTouchDispatcher();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'registerWithTouchDispatcher'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __CCScrollViewDelegate__ of class  LuaScrollView */
#ifndef TOLUA_DISABLE_tolua_get_LuaScrollView___CCScrollViewDelegate__
static int tolua_get_LuaScrollView___CCScrollViewDelegate__(lua_State* tolua_S)
{
    LuaScrollView* self = (LuaScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
    if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__CCScrollViewDelegate__'",NULL);
#endif
#ifdef __cplusplus
    tolua_pushusertype(tolua_S,(void*)static_cast<CCScrollViewDelegate*>(self), "CCScrollViewDelegate");
#else
    tolua_pushusertype(tolua_S,(void*)((CCScrollViewDelegate*)self), "CCScrollViewDelegate");
#endif
    return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_LuaScrollView_open (lua_State* tolua_S)
{
    tolua_open(tolua_S);
    tolua_reg_types(tolua_S);
    tolua_module(tolua_S,NULL,0);
    tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
    tolua_cclass(tolua_S,"LuaScrollView","LuaScrollView","CCScrollView",tolua_collect_LuaScrollView);
#else
    tolua_cclass(tolua_S,"LuaScrollView","LuaScrollView","CCScrollView",NULL);
#endif
    tolua_beginmodule(tolua_S,"LuaScrollView");
    tolua_function(tolua_S,"create",tolua_LuaScrollView_LuaScrollView_create00);
    tolua_function(tolua_S,"delete",tolua_LuaScrollView_LuaScrollView_delete00);
    tolua_function(tolua_S,"scrollViewDidScroll",tolua_LuaScrollView_LuaScrollView_scrollViewDidScroll00);
    tolua_function(tolua_S,"scrollViewDidZoom",tolua_LuaScrollView_LuaScrollView_scrollViewDidZoom00);
    tolua_function(tolua_S,"ccTouchEnded",tolua_LuaScrollView_LuaScrollView_ccTouchEnded00);
    tolua_function(tolua_S,"ccTouchBegan",tolua_LuaScrollView_LuaScrollView_ccTouchBegan00);
    tolua_function(tolua_S,"registerScriptScrollViewHandler",tolua_LuaScrollView_LuaScrollView_registerScriptScrollViewHandler00);
    tolua_function(tolua_S,"unregisterScriptScrollViewHandler",tolua_LuaScrollView_LuaScrollView_unregisterScriptScrollViewHandler00);
    tolua_function(tolua_S,"handleScriptEventHandler",tolua_LuaScrollView_LuaScrollView_handleScriptEventHandler00);
    tolua_function(tolua_S,"registerWithTouchDispatcher",tolua_LuaScrollView_LuaScrollView_registerWithTouchDispatcher00);
    tolua_variable(tolua_S,"__CCScrollViewDelegate__",tolua_get_LuaScrollView___CCScrollViewDelegate__,NULL);
    tolua_endmodule(tolua_S);
    tolua_endmodule(tolua_S);
    return 1;
}