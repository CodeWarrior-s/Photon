#include "dom.hpp"

#include <vector>
#include <mutex>
#include <map>
#include <unordered_map>
#include <iostream>

#define NEGATIVE (-1)
#define AFFIRMATIVE int 1

// TODO: IMPLEMENT THE "text" attribute before i forget it... pending
// TODO: GET THE DATA PARSING PART COMPLETE (THIS DOSE NOT INCLUDE THE 1ST TODO)... checked

using namespace photon;

_dom::_dom()
{
   //type parent children callbacs tag
   dom::nodeInternal node();

   domObjects[nextid] = {dom::_type::_node, 0, {}, {}, {}, 0,""};
   nextid++;
}

_dom::~_dom()
{
}

void _dom::insertNode(const _dom &toinsert)
{
  /*  m.lock();
   toinsert.m.lock();
   dom::id end = toinsert.domObjects.end()->first;
   size_t baseOfset = nextid;
   for (auto &i : toinsert.domObjects)
   {
      dom::nodeInternal temp = i.second;
      for (auto &j : temp.children)
      {
         j += baseOfset;
      }
      domObjects[i.first + baseOfset] = temp;
   }
   nextid += end;
   toinsert.m.unlock();
   m.unlock(); */
}

dom::id _dom::insertNode(const dom::nodeInternal &toinsert)
{
   domObjects[toinsert.parent].children.push_back(nextid);
   domObjects[nextid] = toinsert;
   nextid++;
   return nextid - 1;
}

void _dom::deleteNode(const dom::id &id)
{
   m.lock();
   deleteNodeRec(id);
   m.unlock();
}

void _dom::deleteNodeRec(const dom::id &id)
{
   for (auto &i : domObjects[id].children)
      deleteNodeRec(i);
   domObjects.erase(id);
}

dom::id _dom::createNode(const dom::id &parent, const std::string &tag,const std::map<std::string, std::string>& attributes)
{
   auto temp = &tagNameIds[tag];
   if (*temp)
   {
      *temp = nextTagNameId;
      nextTagNameId++;
   }

   dom::nodeInternal node = {dom::_type::_node, parent, {}, {}, attributes, *temp, ""};
   domObjects[nextid] = node;
   if (parent != 0) domObjects[parent].children.push_back(nextid);
      _dom dom;
   nextid++;
   return nextid - 1;
}

dom::id _dom::crateTextNode(const dom::id& parent, const std::string& text) 
{
   domObjects[nextid] = {dom::_type::text,parent, {}, {}, {}, 0, text};
   nextid++;
   return nextid - 1;
}

std::vector<dom::id> _dom::getNodesByTag(const std::string &tag)
{
   std::vector<dom::id> ret;
   dom::id searchVal = tagNameIds[tag];
   for(const auto & i : domObjects)
      if(i.second.tag == searchVal)
         ret.push_back(i.first);
   
   return ret;
}