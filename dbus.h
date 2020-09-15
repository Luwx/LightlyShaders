#ifndef LIGHTLYSHADERS_ADAPTOR_H
#define LIGHTLYSHADERS_ADAPTOR_H

#include <QtDBus/QDBusAbstractAdaptor>
#include "lightlyshaders.h"
#include <KConfigGroup>

namespace KWin
{
class EffectAdaptor : public QDBusAbstractAdaptor
{
   Q_OBJECT
   Q_CLASSINFO("D-Bus Interface", "org.kde.kwin")

private:
    LightlyShadersEffect *m_effect;

public:
    EffectAdaptor(LightlyShadersEffect *effect) : QDBusAbstractAdaptor(effect), m_effect(effect) { }

public slots:
    Q_NOREPLY void setRoundness(int r)
    {
        KConfigGroup conf = KSharedConfig::openConfig("lightlyshaders.conf")->group("General");
        if (conf.readEntry("dsp", false))
        {
            conf.writeEntry("roundness", r);
            conf.sync();
            m_effect->setRoundness(r);
        }
    }
    Q_NOREPLY void configure() { m_effect->reconfigure(KWin::Effect::ReconfigureAll); }
};
}
#endif //LIGHTLYSHADERS_ADAPTOR_H
