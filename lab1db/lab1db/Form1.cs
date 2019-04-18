using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

using System.Configuration;

namespace lab1db
{
    public partial class Form1 : Form
    {
        SqlConnection connection;
        SqlDataAdapter daChild, daParent;
        DataSet dataset;
        SqlCommandBuilder cb;
        BindingSource bsChild, bsParent;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            daChild.Update(dataset, ConfigurationManager.AppSettings.Get("ChildTable1"));
        }

        private void GridChild_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }

        private void GridParent_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }

        private void button2_Click(object sender, EventArgs e)
        {
            connection = new SqlConnection(@"Data Source = OANA\SQLEXPRESS; Initial Catalog=ChocolateFactoryTema; Integrated Security = True");
            dataset = new DataSet();
            daChild = new SqlDataAdapter(ConfigurationManager.AppSettings.Get("selectAllFromChildren1"), connection);
            daParent = new SqlDataAdapter(ConfigurationManager.AppSettings.Get("selectAllFromParent1"), connection);
            cb = new SqlCommandBuilder(daChild);

            daChild.Fill(dataset, ConfigurationManager.AppSettings.Get("ChildTable1"));
            daParent.Fill(dataset, ConfigurationManager.AppSettings.Get("ParentTable1"));

            DataRelation dr = new DataRelation(ConfigurationManager.AppSettings.Get("FK1"),
                dataset.Tables[ConfigurationManager.AppSettings.Get("ParentTable1")]
                    .Columns[ConfigurationManager.AppSettings.Get("FK")],
                dataset.Tables[ConfigurationManager.AppSettings.Get("ChildTable1")]
                    .Columns[ConfigurationManager.AppSettings.Get("FK")]);
            dataset.Relations.Add(dr);

            bsParent = new BindingSource
            {
                DataSource = dataset,
                DataMember = ConfigurationManager.AppSettings.Get("ParentTable1")
            };

            bsChild = new BindingSource();
            bsChild.DataSource = bsParent;
            bsChild.DataMember = ConfigurationManager.AppSettings.Get("FK1");

            GridChild.DataSource = bsChild;
            GridParent.DataSource = bsParent;
        }
      
    }
}
