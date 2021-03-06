/**
* @file
*
* @section LICENSE
*
* OsmAnd - Android navigation software based on OSM maps.
* Copyright (C) 2010-2013  OsmAnd Authors listed in AUTHORS file
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __RASTERIZATION_STYLE_EVALUATOR_H_
#define __RASTERIZATION_STYLE_EVALUATOR_H_

#include <stdint.h>
#include <memory>

#include <QMap>

#include <OsmAndCore.h>
#include <OsmAndCore/Map/RasterizationStyle.h>
#include <OsmAndCore/Map/RasterizationRule.h>

namespace OsmAnd {

    namespace Model {
        class MapObject;
    }
    class RasterizationRule;

    class OSMAND_CORE_API RasterizationStyleEvaluator
    {
    private:
    protected:
        QMap< OsmAnd::RasterizationStyle::ValueDefinition*, OsmAnd::RasterizationRule::Value > _values;
        
        bool evaluate(uint32_t tagKey, uint32_t valueKey, bool fillOutput, bool evaluateChildren);
        bool evaluate(const std::shared_ptr<OsmAnd::RasterizationRule>& rule, bool fillOutput, bool evaluateChildren);
    public:
        RasterizationStyleEvaluator(const std::shared_ptr<RasterizationStyle>& style, RasterizationStyle::RulesetType ruleset, const std::shared_ptr<OsmAnd::Model::MapObject>& mapObject = std::shared_ptr<OsmAnd::Model::MapObject>());
        RasterizationStyleEvaluator(const std::shared_ptr<RasterizationStyle>& style, const std::shared_ptr<RasterizationRule>& singleRule);
        virtual ~RasterizationStyleEvaluator();

        const std::shared_ptr<RasterizationStyle> style;
        const std::shared_ptr<OsmAnd::Model::MapObject> mapObject;
        const RasterizationStyle::RulesetType ruleset;
        const std::shared_ptr<RasterizationRule> singleRule;

        void setValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, const OsmAnd::RasterizationRule::Value& value);
        void setBooleanValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, const bool& value);
        void setIntegerValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, const int& value);
        void setIntegerValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, const unsigned int& value);
        void setFloatValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, const float& value);
        void setStringValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, const QString& value);

        bool getBooleanValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, bool& value) const;
        bool getIntegerValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, int& value) const;
        bool getIntegerValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, unsigned int& value) const;
        bool getFloatValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, float& value) const;
        bool getStringValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref, QString& value) const;

        void clearValue(const std::shared_ptr<OsmAnd::RasterizationStyle::ValueDefinition>& ref);

        bool evaluate(bool fillOutput = true, bool evaluateChildren = true);

        void dump(bool input = true, bool output = true, const QString& prefix = QString()) const;
    };


} // namespace OsmAnd

#endif // __RASTERIZATION_STYLE_EVALUATOR_H_
