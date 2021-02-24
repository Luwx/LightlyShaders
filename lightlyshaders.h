/*
 *   Copyright © 2015 Robert Metsäranta <therealestrob@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; see the file COPYING.  if not, write to
 *   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *   Boston, MA 02110-1301, USA.
 */

#ifndef LIGHTLYSHADERS_H
#define LIGHTLYSHADERS_H

#include <kwineffects.h>

namespace KWin { class GLTexture; }

class Q_DECL_EXPORT LightlyShadersEffect : public KWin::Effect
{
    Q_OBJECT
public:
    LightlyShadersEffect();
    ~LightlyShadersEffect();

    static bool supported();
    static bool enabledByDefault();

    void setRoundness(const int r);
    void genMasks();
    void genRect();

    void fillRegion(const QRegion &reg, const QColor &c);

    void reconfigure(ReconfigureFlags flags);
#if KWIN_EFFECT_API_VERSION >= 232
    void prePaintWindow(KWin::EffectWindow* w, KWin::WindowPrePaintData& data, std::chrono::milliseconds time);
#else
    void prePaintWindow(KWin::EffectWindow* w, KWin::WindowPrePaintData& data, int time);
#endif
    void paintWindow(KWin::EffectWindow* w, int mask, QRegion region, KWin::WindowPaintData& data);
    virtual int requestedEffectChainPosition() const { return 99; }

protected Q_SLOTS:
    void windowAdded(KWin::EffectWindow *window);

private:
    enum { TopLeft = 0, TopRight, BottomRight, BottomLeft, NTex };
    KWin::GLTexture *m_tex[NTex];
    KWin::GLTexture *m_rect[NTex];
    int m_size, m_rSize, m_alpha;
    bool m_outline;
    QSize m_corner;
    QRegion m_updateRegion;
    KWin::GLShader *m_shader;
    QList<KWin::EffectWindow *> m_managed;
};

#endif //LIGHTLYSHADERS_H

