#pragma once

#include <glm/glm.hpp>
namespace photon
{
   struct style
   {
      struct border
      {
         struct side
         {
            float width;
            glm::vec4 color;
         };
         side top,right,bottom,left;
         struct radius
         {
            float x,y;
         };
         radius topLeft,bottomLeft,bottomRight,topRight;
      };
      border border;
      enum layout{
         inline_,
         block,
         inlineBlock,
         flex,
         inlineFlex,
         grid,
         inlineGrid
      };

      layout layout;
      struct space
      {
         int top, left, bottom, right;
      };
      space margin,padding;
      glm::vec4 bgColor;
   };
   

} // namespace photon
