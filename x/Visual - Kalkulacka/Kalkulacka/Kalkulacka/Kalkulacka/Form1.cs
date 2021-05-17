using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kalkulacka
{


    public partial class Form1 : Form
    {
        double prvni, druhe, mem, vysledek;
        static int operace = 0;

        private void b8_Click(object sender, EventArgs e)
        {
            //Pokud je na displeji 0, přepíše se na 8
            //Pokud na displeji je již nějaké číslo, přidá se 8 za něj
            if (disp.Text == "0") disp.Text = "8";
            else disp.Text = disp.Text + "8";
        }

        private void b9_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "9";
            else disp.Text = disp.Text + "9";
        }

        private void b4_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "4";
            else disp.Text = disp.Text + "4";
        }

        private void b5_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "5";
            else disp.Text = disp.Text + "5";
        }

        private void b6_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "6";
            else disp.Text = disp.Text + "6";
        }

        private void b1_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "1";
            else disp.Text = disp.Text + "1";
        }

        private void b2_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "2";
            else disp.Text = disp.Text + "2";
        }

        private void b3_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "3";
            else disp.Text = disp.Text + "3";
        }

        private void b0_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "0";
            else disp.Text = disp.Text + "0";
        }

        private void des_carka_Click(object sender, EventArgs e)
        {
            //Pokud displej neobsahuje des. čárku, na displej se přidá ","
            if (!disp.Text.Contains(",")) disp.Text += ",";

        }

        private void bc_Click(object sender, EventArgs e)
        {
            //Uplne vymazaní displeje a všech proměnných
            disp.Text = "0";
            prvni = 0;
            druhe = 0;
            operace = 0;
            mezivys.Text = "0";
        }

        private void back_Click(object sender, EventArgs e)
        {
            //Postupne mazani displeje. dokud neni delka 0
            int d;
            d = disp.Text.Length;
            if (d != 0) disp.Text = disp.Text.Remove(d - 1, 1);
            if (disp.Text == "") disp.Text = "0";
            if (disp.Text == "-") disp.Text = "0";
        }

        private void plus_Click(object sender, EventArgs e)
        {
            //Scitani - Ulozim prvni cislo z  displeje do "prvni"
            //Nuluji displej a ulozim druhe cislo do "druhe"
            if (operace == 0)
            {
                prvni = System.Convert.ToDouble(disp.Text);
                operace = 1;
                disp.Text = "0";
            }
            else {
                druhe = System.Convert.ToDouble(disp.Text);
                vysledek = prvni + druhe;
                prvni = vysledek;
                mem = vysledek;
                disp.Text = "0";
                mezivys.Text = System.Convert.ToString(vysledek);
            }

        }

        private void minus_Click(object sender, EventArgs e)
        {
            if (operace == 0)
            {
                prvni = System.Convert.ToDouble(disp.Text);
                operace = 2;
                disp.Text = "0";
            }
            else
            {
                druhe = System.Convert.ToDouble(disp.Text);
                vysledek = prvni - druhe;
                prvni = vysledek;
                mem = vysledek;
                disp.Text = "0";
                mezivys.Text = System.Convert.ToString(vysledek);
            }
        }

        private void nasobeni_Click(object sender, EventArgs e)
        {
            if (operace == 0)
            {
                prvni = System.Convert.ToDouble(disp.Text);
                operace = 3;
                disp.Text = "0";
            }
            else
            {
                druhe = System.Convert.ToDouble(disp.Text);
                vysledek = prvni * druhe;
                prvni = vysledek;
                mem = vysledek;
                disp.Text = "0";
                mezivys.Text = System.Convert.ToString(vysledek);
            }
        }

        private void deleno_Click(object sender, EventArgs e)
        {
            if (operace == 0)
            {
                prvni = System.Convert.ToDouble(disp.Text);
                operace = 4;
                disp.Text = "0";
            }
            else
            {
                druhe = System.Convert.ToDouble(disp.Text);
                if (druhe != 0)
                {
                    vysledek = prvni / druhe;
                    prvni = vysledek;
                    mem = vysledek;
                    disp.Text = "0";
                    mezivys.Text = System.Convert.ToString(vysledek);
                }
                else
                {
                    MessageBox.Show("Nelze dělit nulou!");
                }

            }
        }

        private void rovno_Click(object sender, EventArgs e)
        {
            druhe = System.Convert.ToDouble(disp.Text);

            switch (operace)
            {

                case 1: vysledek = prvni + druhe; break;
                case 2: vysledek = prvni - druhe; break;
                case 3: vysledek = prvni * druhe; break;
                case 4:
                    if (druhe != 0)
                        vysledek = prvni / druhe;
                    else MessageBox.Show("Nelze dělit nulou");

                    break;

                case 5: vysledek = System.Math.Pow(prvni, druhe); break;
            }
            mem = vysledek;
            mezivys.Text = "0";
            disp.Text = System.Convert.ToString(vysledek);
            operace = 0;
        
    }

        private void plusminus_Click(object sender, EventArgs e)
        {
            prvni = System.Convert.ToDouble(disp.Text);
            vysledek = prvni * -1;
            disp.Text = System.Convert.ToString(vysledek);
        }

        private void druha_mocnina_Click(object sender, EventArgs e)
        {
            prvni = System.Convert.ToDouble(disp.Text);
            vysledek = prvni * prvni;
            mem = vysledek;
            disp.Text = System.Convert.ToString(vysledek);
            
        }

        private void lib_mocnina_Click(object sender, EventArgs e)
        {
             if(operace==0)
            {
                prvni = System.Convert.ToDouble(disp.Text);
                operace = 5;
                disp.Text = "0";
            }
            else
            {
                druhe = System.Convert.ToDouble(disp.Text);
                vysledek = System.Math.Pow(prvni, druhe);
                prvni = vysledek;
                mem = vysledek;
                disp.Text = System.Convert.ToString(vysledek);
            }
        }

        private void odmocnina_Click(object sender, EventArgs e)
        {
            disp.Text = System.Convert.ToString(System.Math.Sqrt(System.Convert.ToDouble(disp.Text)));

        }

        private void faktorial_Click(object sender, EventArgs e)
        {
            vysledek = System.Convert.ToDouble(disp.Text);
            if (vysledek == 0) disp.Text = "1"; // faktorial nuly je 1
            else if ((vysledek - System.Math.Round(vysledek)) == 0 && (vysledek > 0)) // podminka, aby cislo muselo byt cele (bez desetin) a vetsi nez nula
            {
                for (double i = vysledek - 1; i > 0; --i) vysledek *= i; // Reseni vypoctu faktorialu pro vetsinu cisel
                disp.Text = System.Convert.ToString(vysledek);
            }
            else MessageBox.Show("Nelze"); // Pokud podminky nahore nebyly splneny tak pro cislo neexistuje faktorial
        }

        private void obracena_hodnota_Click(object sender, EventArgs e)
        {
            prvni = System.Convert.ToDouble(disp.Text);
            vysledek = 1 / prvni;
            mem = vysledek;
            disp.Text = System.Convert.ToString(vysledek);
        }

        private void zaokrouhleni_Click(object sender, EventArgs e)
        {
            disp.Text = System.Convert.ToString(System.Math.Round(System.Convert.ToDouble(disp.Text)));
        }

        private void abs_hodnota_Click(object sender, EventArgs e)
        {
            disp.Text = System.Convert.ToString(System.Math.Abs(System.Convert.ToDouble(disp.Text)));
        }

        private void pi_Click(object sender, EventArgs e)
        {
            disp.Text = System.Convert.ToString(System.Math.PI);
        }

        private void memory_Click(object sender, EventArgs e)
        {
            disp.Text = System.Convert.ToString(mem);
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void DEG_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void sinus_Click(object sender, EventArgs e)
        {
            if (DEG.Checked)
            {
                disp.Text = System.Convert.ToString(System.Math.Round(System.Math.Sin((System.Math.PI * System.Convert.ToDouble(disp.Text)) / 180), 10));
            }
            else if (RAD.Checked)
            {
                disp.Text = System.Convert.ToString(System.Math.Round(System.Math.Sin(System.Convert.ToDouble(disp.Text)), 10));
            }
        }

        private void cosinus_Click(object sender, EventArgs e)
        {
            if (DEG.Checked)
            {
                disp.Text = System.Convert.ToString(System.Math.Round(System.Math.Cos((System.Math.PI * System.Convert.ToDouble(disp.Text)) / 180), 10));
            }
            else if (RAD.Checked)
            {
                disp.Text = System.Convert.ToString(System.Math.Round(System.Math.Cos(System.Convert.ToDouble(disp.Text)), 10));
            }
        }

        private void tangens_Click(object sender, EventArgs e)
        {
            if (DEG.Checked)
            {
                disp.Text = System.Convert.ToString(System.Math.Round(System.Math.Tan((System.Math.PI * System.Convert.ToDouble(disp.Text)) / 180), 10));
            }
            else if (RAD.Checked)
            {
                disp.Text = System.Convert.ToString(System.Math.Round(System.Math.Tan(System.Convert.ToDouble(disp.Text)), 10));
            }
        }

        private void RAD_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void mezivys_TextChanged(object sender, EventArgs e)
        {

        }

        public Form1()
        {
            InitializeComponent();
        }

        private void b7_Click(object sender, EventArgs e)
        {
            if (disp.Text == "0") disp.Text = "7";
            else disp.Text = disp.Text + "7";
        }

        private void disp_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
